
<script setup lang="ts">
import { Device, Environment } from '@/models/devices';
import DeviceComponent from './DeviceComponent.vue';

const props = defineProps({
    environment: { type: Environment, required: true }
}); //Define se é uma propriedade
</script>

<template>
    <section class="flex flex-column"> 
        <h3 class="m-3">{{ props.environment.name }}</h3>
        <div class="flex flex-row">
            <div v-for="(currentDevice, id) in props.environment.devices" :key="id"> <!-- v-bind serve pra fazer uma string ser lida como um atributo -->
            <DeviceComponent :device="currentDevice"/>
        </div>
        </div>
    <hr>     
    </section>
</template>

<style scoped lang="scss">

</style>