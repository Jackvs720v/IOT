<script setup lang="ts">
import { ref } from "vue"; //ref diz que é uma variavel reativa. 

const counter = ref(0); //Mesmo sendo uma constante ele ainda se altera
//const contar = ()=> counter += 1;
const contar = ()=>{
    counter.value +=1;
    console.log(counter);
}
</script>

<template>
    <h1>Hello Devices!</h1>
    <h1>Contagem: {{ counter }}</h1>
    <button @click="contar">  Somar</button>
</template>

<style scoped lang="scss">

</style>