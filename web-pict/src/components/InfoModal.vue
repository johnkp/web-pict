<template>
  <!-- Modal -->
  <div
    class="modal"
    id="appInfoModal"
    tabindex="-1"
    aria-labelledby="appInfoModal"
    aria-hidden="true"
  >
    <div class="modal-dialog">
      <div class="modal-content">
        <div class="modal-header">
          <h1 class="modal-title fs-5" id="exampleModalLabel">Web PICT information</h1>
          <button
            type="button"
            class="btn-close"
            data-bs-dismiss="modal"
            aria-label="Close"
          ></button>
        </div>
        <div class="modal-body">
          <p>
            Web PICT is an independent Wasm port of the Pairwise Independent Combinatorial Testing
            (PICT) tool created by Microsoft. For more information about the PICT model
            syntax visit
            <a
              href="https://github.com/microsoft/pict/blob/main/doc/pict.md"
              target="_blank"
              rel="noopener"
              >PICT</a
            >. This project is not affiliated with Microsoft. For the official Microsoft PICT tool
            source code and its
            <a
              href="https://github.com/microsoft/pict/blob/main/LICENSE.TXT"
              target="_blank"
              rel="noopener"
              >license</a
            >, see the
            <a href="https://github.com/microsoft/pict" target="_blank" rel="noopener"
              >Microsoft PICT GitHub repository</a
            >.
          </p>
          <hr />
          <p>
            <small>
              MIT License.<br /><br />
              Copyright &copy; 2025 JohnKP.<br /><br />
              Permission is hereby granted, free of charge, to any person obtaining a copy of this
              software and associated documentation files (the ""Software""), to deal in the
              Software without restriction, including without limitation the rights to use, copy,
              modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
              and to permit persons to whom the Software is furnished to do so, subject to the
              following conditions:
              <br />
              <br />
              The above copyright notice and this permission notice shall be included in all copies
              or substantial portions of the Software.
              <br />
              <br />
              THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
              INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
              PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
              HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
              CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
              OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
            </small>
          </p>
        </div>
      </div>
    </div>
  </div>
</template>
