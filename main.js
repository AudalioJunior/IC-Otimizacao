const {problem60} = require("./instancias/script")
//const generateLimit = require("./functions/generateLimit")

//const change = require("./functions/neighbor")
const generateResult = require("./functions/generate")

let result = generateResult(problem60)

//let result = generateLimit(problemLimit)
console.log("resultado", result)

//  result.forEach((e) => {
//      e.time = Array() 
//      e.time[0] = e.initial;
//      e.time[1] = e.end;
//  })

//let mak = change(31, result, problem)
//console.log("makespan", mak)
