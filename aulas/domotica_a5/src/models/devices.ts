

export class Device{

    name: string = '';
    velue: boolean = false;


}

export class Environment {
    name: string = '';
    devices: Array<Device> = [];
}

const lampada = new Device();
lampada.name = 'led mesa escritorio'

const ventilador = new Device();
ventilador.name = 'Ventilador de teto'

const quarto = new Environment();
quarto.name = 'quarto';

quarto.devices = [lampada,ventilador]

// //typescript cobra que tenha uma definição
// //? = Opcional
// //any = qualquer coisa

// const numerico: number = 9;
// const texto: String = "";
// const pagamento: 'CRÉDITO'|'DÉBITO' = 'CRÉDITO';
// // const pagamentoarr: Array<'CRÉDITO'|'DÉBITO'> = [
// //     'CRÉDITO',
// //     'DÉBITO'
// // ];
// const nArray: Array<number> = [];
// const array2: number [] = [];

// type usuarioType = {
//     login: string,
//     senha: string,
//     email: string,
//     telefone?: number,
// }

// const usuario: usuarioType = {
//     login: "string",
//     senha: "string123",
//     email: "string@a",
//     telefone: 19999999999
// }

// interface usuarioInterface{
//     login: string,
//     senha: string,
//     email: string,
//     telefone?: number,
// }

// const usuario1: usuarioInterface = {
//     login: "string",
//     senha: "string123",
//     email: "string@a",
//     telefone: 19999999999
// }

// class usuarioC {
//     login: string = '';
//     senha: string = '';
//     email: string = '';
//     telefone?: number ;

//     validarEmail : ()=>{

//     }

// }

// const usuario3: usuarioC = new usuarioC();
// usuario3.login = "fulano";