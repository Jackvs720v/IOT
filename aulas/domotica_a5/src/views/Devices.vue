<script setup lang="ts">
import { Device, Environment } from "@/models/devices";
import { ref, reactive } from "vue"; //ref diz que é uma variavel reativa. 

const ar: Device = reactive(new Device());
ar.name = "Ar condicionado Samsung";
ar.state = true;
ar.icon = 'mode_cool';

const tv: Device = reactive(new Device());
tv.name = "Smart TV LG";
tv.icon = 'tv';

const iluminacao: Device = reactive(new Device())
iluminacao.name = "Lâmpada LED";
iluminacao.state = true;
iluminacao.icon = 'light';

const tomada: Device = reactive(new Device())
tomada.name = "Tomada Inteligente";
tomada.state = false;
tomada.icon = 'power';

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


</script>

<template>
    <h1>Seus Dispositivos: </h1>
    <div v-for="(currentEnvironment, envId) in environments" :key="envId">
    <h3>{{ currentEnvironment.name }}</h3>
    <div v-for="(currentDevice, id) in currentEnvironment.devices" :key="id"> <!-- v-bind serve pra fazer uma string ser lida como um atributo -->
        <h5>{{ currentDevice.name }}</h5>
        <span class="icons material-icons-round">{{ currentDevice.icon }}</span>
        <!-- <h5>{{ ar.state }}</h5> -->
        <div v-bind:class="`button-${currentDevice.state}`"> <!-- template string segue o seguinte formato = `button-${ar.state}` -->
            <button class="on">ON</button>
            <button class="off">OFF</button>
        </div>        
    </div>
    <hr>
</div>


   
</template>

<style scoped lang="scss">
.button-true{
    .on{
    background-color: green;
    }
    .off{
        background-color: white;
    }
}
.button-false{
    .on{
        background-color: white;    
    }
    .off{
    background-color: red;
    }

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