<script setup lang="ts">
// @ts-expect-error Generated file
import Pict from '../assets/pict.js'
import { ref, watch } from 'vue'

const inputPictModel = defineModel<string>('pictmodel')
const generationTimeInMs = ref<number>()
const columns = ref([])
const testCaseCombinations = ref([])
const totalCombinations = ref<number>(0)
const warningMessage = ref('')
const pictEngine = await Pict()

interface IPictData {
  [key: string]: string

  value: string
}

watch(inputPictModel, async (newModel: any) => {
  if (newModel.trim().length > 0) {
    const startTime = new Date()
    const output = pictEngine.run_pict(newModel)
    try {
      const pictResult = JSON.parse(output)
      if (pictResult.success && pictResult.result) {
        totalCombinations.value = pictResult.totalCombinations
        warningMessage.value = pictResult.message
        const first = pictResult.result[0]
        columns.value = first.map((key: any) => key.key)
        testCaseCombinations.value = pictResult.result.map((item: any) => {
          const result = {}
          item.forEach((key: IPictData) => {
            ;(result as any)[key.key] = key.value
          })
          return result
        })
        const endTime = new Date()
        generationTimeInMs.value = (endTime as any) - (startTime as any)
      } else {
        warningMessage.value = pictResult.message || 'Could not process the input.'
      }
    } catch (e) {
      console.error('Cannot parse:', e)
      warningMessage.value = 'Could not parse result from PICT'
    }
  } else {
    testCaseCombinations.value = []
    columns.value = []
    warningMessage.value = ''
    generationTimeInMs.value = 0
  }
})

const copyToClipboard = () => {
  let text = columns.value.join('\t') + '\n'
  text += testCaseCombinations.value.map((row) => Object.values(row).join('\t')).join('\n')
  navigator.clipboard
    .writeText(text)
    .then(() => {
      //alert('Output copied to clipboard!')
    })
    .catch((err) => {
      console.error('Could not copy text: ', err)
    })
}
</script>

<template>
  <div class="row ps-2 pe-2">
    <textarea
      class="form-control"
      rows="12"
      v-model="inputPictModel"
      placeholder="Enter a PICT model or load one of the examples via the Examples button above. All model data is processed in the browser and will not be sent to any server."
    ></textarea>
  </div>
<!--  <hr-->
<!--    v-if="warningMessage || testCaseCombinations.length > 0"-->
<!--    class="border border-bg border-2 opacity-50"-->
<!--  />-->
  <div class="row mt-4" v-if="warningMessage ||testCaseCombinations.length > 0">
    <div class="d-flex align-items-center">
      <h3 class="fs-6 me-auto">Testcases</h3>
    </div>
  </div>
  <div v-if="warningMessage" class="alert alert-warning">
    {{ warningMessage }}
  </div>
  <div class="overflow-auto" style="max-height: 450px">
    <table class="table table-sm table-striped">
      <thead>
        <tr>
          <th v-for="(value, key) in columns" :key="key">
            {{ value }}
          </th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="(value, rowkey) in testCaseCombinations" :key="rowkey">
          <td v-for="(data, datakey) in value" :key="rowkey + datakey">{{ data }}</td>
        </tr>
      </tbody>
    </table>
  </div>
  <div class="row mt-2" v-if="testCaseCombinations.length > 0">
    <div class="d-flex flex-row-reverse align-items-baseline">
      <button type="button" class="btn btn-light btn-sm" @click="copyToClipboard()">
        Copy testcases to clipboard
      </button>
      <div class="text-muted me-5">
        <small>
          Generated {{ testCaseCombinations.length }} pairwise combinations  in {{ generationTimeInMs }}ms</small
        >
      </div>
    </div>
  </div>
</template>

<style scoped></style>
