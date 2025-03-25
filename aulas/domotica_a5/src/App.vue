<script setup lang="ts">
import { ref, computed } from 'vue';
import { RouterLink, RouterView, useRouter } from 'vue-router'

// const menus = ref([
//   'Home','Cart','Products'
// ]);

const router = useRouter();
//setup é para executar o script uma vez só
//computed é quando precisa ser reativo e precisa ser atualizado a todo momento, mas apenas o evento do código
const buttonRouteLabel = computed(()=> router.currentRoute.value.name === 'devices'?
'Gerenciamento': 'Dispositivos');

const changePage =()=>{
   router.currentRoute.value.name === 'devices'?
      router.push('/management') : router.push('/');

      //buttonRouteLabel.value = `${router.currentRoute.value.name as string}`;
}
</script>



<template>
    <!-- <div v-for="menu in menus">
    <RouterLink  :to="`/${menu}`">menu</RouterLink>
  </div> -->
   <button @click="changePage()">Página {{ buttonRouteLabel }}</button>
   <!-- <RouterLink to="/management"> Gerenciamento</RouterLink> -->

<RouterView />
</template>

<style scoped>

</style>
