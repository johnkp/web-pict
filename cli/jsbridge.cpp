#include "jsbridge.h"

#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include <locale>
#include <string>

#include "gcd.h"

using namespace pictcli_gcd;
using namespace std;
using namespace emscripten;

std::wstring run_pict(const std::wstring& inputModel) {
    CModelData modelData;
    modelData.Format = L"json";

    wostringstream jsonResult;

    if (!modelData.ReadModelFromString(inputModel)) {
        jsonResult << R"({ "success": false, "message": "Cannot read model" })";
        return jsonResult.str();
    }

    GcdRunner gcdRunner(modelData);

    ErrorCode err = gcdRunner.Generate();
    if (err != ErrorCode::ErrorCode_Success) {
        jsonResult << R"({ "success": false, "message": "Generator error" })";
        return jsonResult.str();
    }

    CResult result = gcdRunner.GetResult();

    size_t totalCombinations = modelData.GetTotalCombinations();

    wostringstream errorStream;
    result.GetConstraintWarnings(errorStream);

    wostringstream outputStream;
    if (modelData.Format == L"json") {
        result.PrintOutputJson(modelData, outputStream);
    } else {
        result.PrintOutput(modelData, outputStream);
    }

    jsonResult << R"({ "success": true, "message": ")" << escape_json(errorStream.str()) << R"(", "totalCombinations": )" << totalCombinations << R"(, "result": )" << outputStream.str() << " }";
    return jsonResult.str();
}

wstring escape_json(const wstring &inputString) {
    std::wostringstream outputStream;
    for (wchar_t c: inputString) {
        switch (c) {
            case '"': outputStream << "\\\"";
                break;
            case '\\': outputStream << "\\\\";
                break;
            case '\b': outputStream << "\\b";
                break;
            case '\f': outputStream << "\\f";
                break;
            case '\n': outputStream << "\\n";
                break;
            case '\r': outputStream << "\\r";
                break;
            case '\t': outputStream << "\\t";
                break;
            default:
                if ('\x00' <= c && c <= '\x1f') {
                    outputStream << L"\\u" << std::hex << std::setw(4) << std::setfill(L'0') << static_cast<int>(c);
                } else {
                    outputStream << c;
                }
        }
    }

    return outputStream.str();
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("run_pict", &run_pict);
}
