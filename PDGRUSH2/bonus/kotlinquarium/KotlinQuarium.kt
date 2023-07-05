
object Kotlinquarium {

    val fishes = mutableListOf<Fish>()
    val plants = mutableListOf<Plant>()

    fun addFish(fish: Fish) {
        fishes.add(fish)
    }

    fun addPlant() {
        plants.add(Plant())
    }

    fun passTime() {
        val copyFishes = fishes.toMutableList()
        copyFishes.forEach {
            val copyFishesWithoutIt = copyFishes.toMutableList()
            copyFishesWithoutIt.remove(it)

            if (!fishes.contains(it))
                return
            when (it) {
                is CarnivoreFish -> it.eat(copyFishesWithoutIt.random())
                is VeganFish -> it.eat(plants.random())
            }
        }
    }
}

class Plant

abstract class Fish(open val name: String, open val sex: String)

open class CarnivoreFish(override val name: String, override val sex: String) : Fish(name, sex) {
    fun eat(fish: Fish) {
        println("$name eats ${fish.name}")
        Kotlinquarium.fishes.remove(fish)
    }
}

open class VeganFish(override val name: String, override val sex: String) : Fish(name, sex) {
    fun eat(plant: Plant) {
        println("$name eats a plant")
        Kotlinquarium.plants.remove(plant)
    }
}

class MerouFish(override val name: String, override val sex: String) : CarnivoreFish(name, sex)
class ThonFish(override val name: String, override val sex: String) : CarnivoreFish(name, sex)
class ClownFish(override val name: String, override val sex: String) : CarnivoreFish(name, sex)

class SoleFish(override val name: String, override val sex: String) : VeganFish(name, sex)
class BarFish(override val name: String, override val sex: String) : VeganFish(name, sex)
class CarpeFish(override val name: String, override val sex: String) : VeganFish(name, sex)


fun main() {
    Kotlinquarium.addFish(MerouFish("zizi", "Male"))
    Kotlinquarium.addFish(ThonFish("zizi2", "Male"))
    Kotlinquarium.addFish(ClownFish("zizi3", "Female"))

    Kotlinquarium.addFish(SoleFish("zezette1", "Female"))
    Kotlinquarium.addFish(BarFish("zezette2", "Male"))
    Kotlinquarium.addFish(CarpeFish("zezette3", "Female"))

    Kotlinquarium.addPlant()
    Kotlinquarium.addPlant()
    Kotlinquarium.addPlant()
    Kotlinquarium.passTime()
}



