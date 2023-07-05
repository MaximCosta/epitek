#include "Ingredients.hpp"

namespace Plazza {
    Ingredients::Ingredients() {
        _ingredients = {
                {Ingredient::Dough,      5},
                {Ingredient::Tomato,     5},
                {Ingredient::Gruyere,    5},
                {Ingredient::Ham,        5},
                {Ingredient::Mushrooms,  5},
                {Ingredient::Steak,      5},
                {Ingredient::Eggplant,   5},
                {Ingredient::GoatCheese, 5},
                {Ingredient::ChiefLove,  5}
        };
    }

    std::size_t Ingredients::getIngredientQuantity(Ingredient ingredient) const {
        return _ingredients.at(ingredient);
    }

    void Ingredients::refillIngredient(Ingredient ingredient) {
        _ingredients.at(ingredient) += 1;
    }
} // Plazza