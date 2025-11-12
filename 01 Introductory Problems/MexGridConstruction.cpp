// Função externa
def makeAdder(x: Int): Int => Int = {
  // 'x' é capturado pela função interna
  val innerFunction = (y: Int) => x + y
  return innerFunction
}

val addFive = makeAdder(5) // 'makeAdder' retorna, mas 'x=5' persiste
val addTen = makeAdder(10) // 'makeAdder' retorna, mas 'x=10' persiste

println(addFive(2)) // Imprime 7 (usando o 'x=5' persistente)
println(addTen(2))  // Imprime 12 (usando o 'x=10' persistente)
