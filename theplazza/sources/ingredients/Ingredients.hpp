#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_INGREDIENTS_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_INGREDIENTS_HPP

#include <iostream>
#include <unordered_map>

namespace Plazza {
    enum Ingredient {
        Dough,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove
    };

    class Ingredients {
    public:
        Ingredients();
        ~Ingredients() = default;

        std::size_t getIngredientQuantity(Ingredient ingredient) const;
        void refillIngredient(Ingredient ingredient);

    private:
        std::unordered_map<Ingredient, std::size_t> _ingredients;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_INGREDIENTS_HPP
