<script setup lang="ts">
import DeviceComponent from "@/components/DeviceComponent.vue";
import EnvironmentComponent from "@/components/EnvironmentComponent.vue";
import { Device, Environment } from "@/models/devices";
import { ref, reactive } from "vue"; //ref diz que é uma variavel reativa. 

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

const changeState = () =>{

}


</script>

<template>
    <main class="flex flex-column justify-content-center align-items-center">
        <h1>Seus Dispositivos: </h1>
       <section class="environments border-round-sm">
        <div v-for="(currentEnvironment, envId) in environments" :key="envId">
            <EnvironmentComponent :environment ="currentEnvironment"/>
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

<!-- const counter = ref(0); //Mesmo sendo uma constante ele ainda se altera
//const contar = ()=> counter += 1;
 const contar = ()=>{
     counter.value +=1;
     console.log(counter);
 } -->
    <!-- <h1>Contagem: {{ counter }}</h1>
    <button @click="contar">  Somar</button> -->