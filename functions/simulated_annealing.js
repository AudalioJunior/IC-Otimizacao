const {problem60} = require("../instancias/script") // Import da instância a ser trabalhada
const change = require("./neighbor") // Estrutura de troca de vizinhança
const generateResult = require("./generate") // Gerar solução

var result = Array()

//Gerando o Makespan Inicial
const bestChoice = function(){
    result = generateResult(problem60)
    let makespan = Number()
    result.forEach((e) => {
        if(e.end > makespan){
            makespan = e.end
        }
    })
    return makespan
}


// Função simullated annealing
const simulated = function(solution){

    let t = 100; //Temperatura relativa ao primeiro laço
    let tc = 0; // Temperatura minima
    let alpha = 0.99; // alpha
    let s_max = 50; // SAmax
    let iterT = 0; //IterT
    let choice = [0, 1]; // (x E [0, 1])
    let eulerNumber = 2.7182;// Número de Euler
    let bestSolution = solution
    let currentSolution = solution
    let listProblems = [...result]
    
    while(t > tc){
        while(iterT < s_max){
            iterT += 1;

            // Seleção randômica
            let lengthTimeLine = problem60.length;
            let randomIndex = Math.floor(Math.random() * lengthTimeLine);
            let valueChange = problem60[randomIndex].id;
            
            
            let results = [...listProblems]
            let resultChange = change(valueChange, results, problem60); // GERAR (um vizinho S')
            

            let s_row = resultChange == undefined ? solution : resultChange;

            let delta = s_row - currentSolution;
            if(delta < 0){
                currentSolution = s_row
                if(s_row < bestSolution){
                    bestSolution = s_row
                }
            }else{

                let x = choice[Math.floor() * choice.length]
                
                let exp = -delta/t
                if (x < Math.pow(eulerNumber, exp)){
                    currentSolution = s_row
                }          

            }
        }
        iterT = 0;
        t = t - alpha //ajustar
    }
    return bestSolution

}

let mak = bestChoice()
result.forEach((e) => {
    e.time = Array() 
    e.time[0] = e.initial;
    e.time[1] = e.end;
})

console.log("Solution", simulated(mak))