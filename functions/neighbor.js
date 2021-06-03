const process = [
    { id: 0, pred: [-1, -1, -1], custo: -1 },
    { id: 1, pred: [0, -1, -1], custo: 4 },
    { id: 2, pred: [0, -1, -1], custo: 10 },
    { id: 3, pred: [0, -1, -1], custo: 5 },
    { id: 4, pred: [1, -1, -1], custo: 1 },
    { id: 5, pred: [1, -1, -1], custo: 5 },
    { id: 6, pred: [2, -1, -1], custo: 7 },
    { id: 7, pred: [2, -1, -1], custo: 4 },
    { id: 8, pred: [2, -1, -1], custo: 3 },
    { id: 9, pred: [4, 6, 3], custo: 2 },
]

var result = [
    { id: 0, time: [0, 0] },
    { id: 1, time: [0, 4] },
    { id: 3, time: [0, 5] },
    { id: 2, time: [0, 10] },
    { id: 4, time: [4, 5] },
    { id: 5, time: [4, 9] },
    { id: 8, time: [10, 13] },
    { id: 7, time: [10, 14] },
    { id: 6, time: [10, 17] },
    { id: 9, time: [17, 19] },
]

const change = (task, result, process) => {
 
    if(task !== 1){
        //Recuperando do resultados
        let infoTask = Object();
        let indexProcess = Number()
        result.forEach((e, i) => {
            if (e.id === task) {
                infoTask = { ...e }
                indexProcess = i
            }
        })
    
        
        infoTask.pred = process[indexProcess].pred;
    
        //Buscar as possíveis trocas
      
   
        let currentPred = infoTask.pred.filter((e) => e != -1);
        let allLastTimes = Array()
    
        currentPred.forEach((e) => {
            result.forEach((el) => {
                if (e === el.id) {
                    let value = el.time[1]
                    allLastTimes.push(value)
                }
            })
    
        })
    
    
    
        //Valor Máximo para montar a linha do tempo
      
        let maxLastTime = allLastTimes.reduce((a, b) => {
            return Math.max(a, b)
        })
    
    
        let maxCurrentTime = infoTask.time[1]
    
        let timeLineValues = Array() // Valores possíveis a troca
    
    
        result.forEach((e) => {
            if (e.id != task && e.time[0] >= maxLastTime && e.time[1] <= maxCurrentTime) {
                timeLineValues.push(e)
            }
        })
        let lengthTimeLine = timeLineValues.length; 
    
        //Se for vazio, não inicia
        if (lengthTimeLine > 0){
        //Programar 1 troca
        let randomIndex = Math.floor(Math.random() * lengthTimeLine);
        
        let oneValue = timeLineValues[randomIndex]
        delete infoTask.pred
    
        let valueCust = oneValue.time[1] - oneValue.time[0]
        let curretCust = infoTask.time[1] - infoTask.time[0]
    
        infoTask.time[0] = oneValue.time[0]
        infoTask.time[1] = infoTask.time[0] + curretCust;
    
        oneValue.time[0] = infoTask.time[1];
        oneValue.time[1] = oneValue.time[0] + valueCust;
    
        result.forEach((e) => {
            if (e.id === infoTask.id) {
                e = infoTask;
            } else if (e.id === oneValue.id) {
                e = oneValue;
            }
        })
    
        //Organizar a impressao
        let lastIndex = result.findIndex((item) => item.id == oneValue.id)
        let currentIndex = result.findIndex((item) => item.id == infoTask.id)
    
        result[lastIndex] = infoTask
        result[currentIndex] = oneValue
    
        var makespan = Number()
    
        result.forEach((e) => {
            if(e.time[1] > makespan){
                makespan = e.time[1] 
            }
        })
    
        return makespan
    }else{
        console.log("Troca não é possivel")
    }
    }else{
        console.log("troca não possivel")
    }


}

module.exports = change