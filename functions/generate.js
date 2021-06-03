



function generateResult(list) {
    let problemList = [ ...list]
    let resultList = Array()
    let firstValue = problemList.filter(e => e.pred === null)
    let candidates = problemList.filter(e => e.pred != null)

    //Processamento do primeiro resultado
    firstValue.forEach((e) => {

        let value = {
            id: e.id,
            initial: 0,
            end: 0 + e.cust
        }
        resultList.push(value)

    })

    //Processamento dos outros valores
    var valorLoop = 0

    while(valorLoop <= candidates.length){
        
        candidates.forEach((e) =>{


            if(e.add === false){
            
                let presentValue = []
                
                //Verificar a possibilidade de adição
                e.pred.forEach((pred)=>{
                   
                    let present = resultList.find(e => e.id == pred)
                    
                    if(present != undefined){
                        presentValue.push(present)
                    }
                   
                })
               
           
                //autorização para adicionar
                if(e.pred.length == presentValue.length){
                    
                    
                    e.add = true
                    let bigValue = Number()
                 
                    presentValue.forEach((value) => {
                        if(value.end > bigValue){
                            bigValue = value.end
                        }
                    })

                    let taskForAdd = {
                        id: e.id,
                        initial: bigValue,
                        end: bigValue + e.cust
                    }

                    resultList.push(taskForAdd)            
                    
                }
            
             
            }
        })
       
            valorLoop++
        
    
    }
    



    return resultList


}

module.exports = generateResult