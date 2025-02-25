import { createRouter, createWebHistory } from 'vue-router'
import Devices from '@/views/Devices.vue'
import Management from '@/views/Management.vue'
import NotFound from '@/views/NotFound.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
   component: Devices,
   path: '/'
  },
  {
    component: Management,
    path: '/management'
  },
  {
    component: NotFound,
    path: '/:pathMatch(.*)*' //Serve para se digitar alguma rota que não tenha, ele vá para not found
  },
  ],
})

export default router
