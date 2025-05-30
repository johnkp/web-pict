<script setup lang="ts">
import WebPict from './components/WebPict.vue'
import InfoModal from './components/InfoModal.vue'
import { ref } from 'vue'
import examples from './examples.json'

const pictModel = ref('')
</script>

<template>
  <div class="container-xxl">
    <div class="d-flex mt-2 mb-2">
      <h1 class="fs-4 me-auto">Pairwise Independent Combinatorial Testing</h1>
      <div class="dropdown">
        <button
          class="btn btn-secondary dropdown-toggle btn-sm me-2"
          type="button"
          data-bs-toggle="dropdown"
          aria-expanded="false"
        >
          Examples
        </button>
        <ul class="dropdown-menu">
          <li v-for="(example, key) in examples" :key="key">
            <a
              class="dropdown-item"
              href="#"
              @click="
                () => {
                  pictModel = example.model
                }
              "
              >{{ example.name }}</a
            >
          </li>
        </ul>
      </div>
      <div>
        <button
          type="button"
          class="btn btn-info btn-sm"
          data-bs-toggle="modal"
          data-bs-target="#appInfoModal"
        >
          Info
        </button>
      </div>
    </div>
    <Suspense>
      <WebPict v-model:pictmodel="pictModel" />
    </Suspense>
    <InfoModal />
  </div>
</template>

<style scoped></style>
