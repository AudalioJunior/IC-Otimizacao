const { problemLimit } =  require("../instancias/script")


function refreshTimeLine (timeLine, value) {
    //Tratar Linha do Tempo Vazia
    if(timeLine.length == 0){
        let i = value.begin
        while (i <= value.end){
            let  time = {
                time: i,
                values: Array()
            }
            time.values.push(value.id)
            timeLine.push(time)
            i += 1
        }
    }
    return timeLine
    
}



function generateLimit(problem, resource){
    let problems = [...problem]
    let resources = [... resource]
    let firstValues = problems.filter(e => e.pred === null)
    // let candidates = problems.filter(e => e.pred != null)
    let results = Array()
    let timeLine = Array()

    //Primeiros Valores
    firstValues.forEach((e, i) => {
        if(i == 0){
            let value = {
                id: e.id,
                begin: 1,
                end: e.d,
                cust: [e.c1, e.c2]
            }
            e.add = true,
            results.push(value)
            timeLine = refreshTimeLine(timeLine, value)
        }else{
            timeLine.forEach(time => {
                
            })
        }
    
    })
    console.log(timeLine)


}

generateLimit(problemLimit, [5,5])