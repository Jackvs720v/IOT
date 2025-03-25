import { ref, computed } from 'vue'
import { defineStore } from 'pinia'
import type { Environment } from '@/models/devices'

export type Repository = {
  environments: Array<Environment>
}

export const useDeviceRepository = defineStore('device-repository', {
  state: (): Repository => ({
  environments: []
  }), //estado das variaveis, onde as variaveis ficam
  actions: {
    addEnvironment(newEnvironment: Environment){
      this.environments.push(newEnvironment);
    },
    removeEnvironment(name: string){
      const index = this.environments.findIndex(env => env.name === name);
      if (index >= 0){
        this.environments.splice(index,1);
      }
    }
  }, //operações que alteram as variaveis
  getters: {} //
})
