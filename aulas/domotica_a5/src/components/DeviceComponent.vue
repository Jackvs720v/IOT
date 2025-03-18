
<script setup lang="ts">
import { Device } from '@/models/devices';

const props = defineProps({
    device: { type: Device, required: true }
}); //Define se é uma propriedade
</script>

<template>
    <section class="flex flex-column text-center align-items-center 
    justify-content-center"> 
         <h5>{{ props.device.name }}</h5>
        <span class="icons material-icons-round">{{ props.device.icon }}</span>
        <!-- <h5>{{ ar.state }}</h5> -->
        <div v-bind:class="`device-buttons button-${props.device.state}`"> <!-- template string segue o seguinte formato = `button-${ar.state}` -->
            <button @click="()=> props.device.state = true" class="on">ON</button>
            <button @click="()=> props.device.state = false" class="off">OFF</button>
        </div>      
    </section>
</template>

<style scoped lang="scss">
    section{
        background-color: var(--background-device-color);
        width: 10rem;
        height: 6.5rem;
        margin: 0.5rem;         

        .icons{
           font-size: 1.5rem;
            margin: 0.5rem;
            color: var(--device-icon-color);
        }
        .device-buttons button{
            border: none;
            padding: 0.6rem;
            cursor: pointer;
            &:hover{
                opacity: 0.6;
                transform: scale(1.05);
                transition: 0.5s    
            };
        }
        
    }
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