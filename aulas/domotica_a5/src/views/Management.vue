<script setup lang="ts">
import DeviceComponent from "@/components/DeviceComponent.vue";
import EnvironmentComponent from "@/components/EnvironmentComponent.vue";
import { Device, Environment } from "@/models/devices";
import { useDeviceRepository } from "@/stores/deviceRepository";
import { ref, reactive, onMounted } from "vue"; //ref diz que é uma variavel reativa. 

const selectedEnvironment = ref(new Environment());
const newEnv = reactive(new Environment());
const showNewEnvForm = ref(false);

const saveNewEnv = () => {
    useDeviceRepository().addEnvironment(newEnv);
    showNewEnvForm.value = false;
}

onMounted(() => {
    selectedEnvironment.value = useDeviceRepository().environments[0] ?? new Environment();

}
)

const changeState = () =>{

}
</script>

<template>
    <main class="flex flex-column text-center justify-content-center align-items-center">
        <h1>Gerencie seus dispositivos 😎</h1>
        <section class="environments flex flex-column border-round-sm">
            <div class="flex flex-row m-3">
                <label for="selectedEnv" class="mr-3">Ambiente:</label>
                <select id="selectedEnv" v-model="selectedEnvironment">
                    <option v-for="(currentEnv, envId) in useDeviceRepository().environments" key="envId" 
                     :value="currentEnv">{{ currentEnv.name }}
                    </option>
                   
                    <option v-if="useDeviceRepository().environments.length == 0" value="">Sem ambientes</option>  
                    <option value="" v-if="selectedEnvironment.devices.length == 0">
                        Selecione
                    </option> 
                </select>
                <button @click="()=> showNewEnvForm = true">
                    <span class="icons material-icons-round" >add</span>
                </button>
                <div>
                    <label for="">Nome:</label>
                    <input type="text" v-model="newEnv.name">
                </div>
                <button @click="saveNewEnv" v-if="showNewEnvForm">
                    <span class="icons material-icons-round">save</span>
                </button>
            </div>
    <div>
        <EnvironmentComponent :showDevButtons="false" :environment="selectedEnvironment"/>
    </div>
        </section>
    </main>
</template>

<style scoped lang="scss">
    main{
        width: 100vw;
        min-height: 100vh;

    .environments{
        width: 90vh;
        min-height: 95vh;
        background-color: var(--background-envs-color);
        box-shadow: rgba(0, 0, 0, 0.16) 0px 10px 36px 0px, rgba(0, 0, 0, 0.06) 0px 0px 0px 1px;    }
    }
</style>