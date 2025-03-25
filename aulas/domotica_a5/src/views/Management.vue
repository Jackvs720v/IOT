<script setup lang="ts">
import DeviceComponent from "@/components/DeviceComponent.vue";
import EnvironmentComponent from "@/components/EnvironmentComponent.vue";
import { Device, Environment } from "@/models/devices";
import { ref, reactive, onMounted } from "vue"; //ref diz que é uma variavel reativa. 

const selectedEnvironment = ref(new Environment());


const ar: Device = reactive(new Device());
ar.name = "Ar condicionado Samsung";
ar.state = true;
ar.icon = 'heat_pump';
ar.fav = 'favorite';

const tv: Device = reactive(new Device());
tv.name = "Smart TV LG";
tv.icon = 'tv';
tv.fav = 'favorite';


const iluminacao: Device = reactive(new Device())
iluminacao.name = "Lâmpada LED";
iluminacao.state = true;
iluminacao.icon = 'light';
iluminacao.fav = 'favorite';


const tomada: Device = reactive(new Device())
tomada.name = "Tomada Inteligente";
tomada.state = false;
tomada.icon = 'power';
tomada.fav = 'favorite';

//Environments

const sala: Environment = reactive(new Environment());
sala.name = 'Sala de Estar';
sala.devices = [ar,tv,iluminacao];

const quarto: Environment = reactive(new Environment());
quarto.name = 'Quarto de Hóspedes';
quarto.devices = [tomada];

const environments: Array<Environment> = reactive([]);
 environments.push(sala);
 environments.push(quarto);

onMounted(() => {
    selectedEnvironment.value = environments[0] ?? new Environment();

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
                    <option v-for="(currentEnv, envId) in environments" key="envId" 
                     :value="currentEnv">{{ currentEnv.name }}
                    </option>
                   
                    <option v-if="environments.length == 0" value="">Sem ambientes</option>  
                    <option value="" v-if="selectedEnvironment.devices.length == 0">
                        Selecione
                    </option> 
                </select>
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