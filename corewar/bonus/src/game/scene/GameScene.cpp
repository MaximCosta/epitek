/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <cstring>
#include <iostream>
#include "../../../include/engine/Engine.hpp"
#include "../../../include/game/Game.hpp"

static const std::string CURSOR = "./bonus/resources/Cursor.png";
static const std::string COREWAR_BACKGROUND =
    "./bonus/resources/CorewarBackground.png";
static const std::string SETTINGS_BUTTON =
    "./bonus/resources/SettingsButton.png";
static const std::string PLAY_BUTTON = "./bonus/resources/PlayButton.png";
static const std::string NEXT_CYCLE_BUTTON =
    "./bonus/resources/NextCycleButton.png";
static const std::string DIOGO_FONT_PATH = "./bonus/resources/diogo.ttf";

bool MousePress = false;

sf::Color cg::GameScene::getTeamColor(int textOwnerId, bool bold)
{
    sf::Color cyan = sf::Color(0, 255, 255, bold ? 255 : 170);
    sf::Color red = sf::Color(255, 0, 0, bold ? 255 : 170);
    sf::Color green = sf::Color(0, 255, 0, bold ? 255 : 170);
    sf::Color blue = sf::Color(0, 0, 255, bold ? 255 : 170);

    switch (textOwnerId) {
        case 1: return cyan;
        case 2: return red;
        case 3: return green;
        case 4: return blue;
        default: return sf::Color(92, 92, 92, 255);
    }
}

void cg::GameScene::fillChampionsProperties()
{
    list_t *champion = this->corewar->champions;
    int y = 200;

    while (champion) {
        champion_t *champ = (champion_t *) champion->value;
        std::shared_ptr<cg::TextComponent> nameProp =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("name " + std::to_string(champ->id),
                    std::string(champ->name), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent>
            progNb = // std::to_string(champ->id)
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("progNb " + std::to_string(champ->id),
                    std::string("0"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> carry =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("carry " + std::to_string(champ->id),
                    std::string("1"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> couldown =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("couldown " + std::to_string(champ->id),
                    std::string("2"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> registers =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("registers " + std::to_string(champ->id),
                    std::string("3"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> live =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("live " + std::to_string(champ->id),
                    std::string("4"), DIOGO_FONT_PATH));

        nameProp->setPosition(sf::Vector2f(120, y));
        y += 41;
        progNb->setPosition(sf::Vector2f(135, y));
        y += 20;
        carry->setPosition(sf::Vector2f(120, y));
        y += 20;
        couldown->setPosition(sf::Vector2f(145, y));
        y += 20;
        registers->setPosition(sf::Vector2f(145, y));
        y += 40;
        live->setPosition(sf::Vector2f(110, y));
        nameProp->setCharacterSize(7);
        progNb->setCharacterSize(7);
        carry->setCharacterSize(7);
        couldown->setCharacterSize(7);
        registers->setCharacterSize(7);
        live->setCharacterSize(7);
        this->addComponent(nameProp);
        this->addComponent(progNb);
        this->addComponent(carry);
        this->addComponent(couldown);
        this->addComponent(registers);
        this->addComponent(live);
        champion = champion->next;
        y += 58;
    }
}

void cg::GameScene::fillVmProperties()
{
    std::shared_ptr<cg::TextComponent> cycleProp =
        std::make_shared<cg::TextComponent>(
            cg::TextComponent("cycle count prop",
                std::to_string(corewar->vm->cycles), DIOGO_FONT_PATH));
    std::shared_ptr<cg::TextComponent> checkIntervalProp =
        std::make_shared<cg::TextComponent>(
            cg::TextComponent("check interval prop",
                std::to_string(corewar->vm->check_interval), DIOGO_FONT_PATH));

    cycleProp->setFillColor(sf::Color::White);
    checkIntervalProp->setFillColor(sf::Color::White);
    cycleProp->setCharacterSize(30);
    checkIntervalProp->setCharacterSize(30);
    cycleProp->setPosition(sf::Vector2f(700, 102));
    checkIntervalProp->setPosition(sf::Vector2f(885, 102));
    cycleProp->setOrigin(sf::Vector2f(cycleProp->getLocalBounds().width / 2,
        cycleProp->getLocalBounds().height / 2));
    checkIntervalProp->setOrigin(
        sf::Vector2f(checkIntervalProp->getLocalBounds().width / 2,
            checkIntervalProp->getLocalBounds().height / 2));
    this->addComponent(cycleProp);
    this->addComponent(checkIntervalProp);
}

void cg::GameScene::loadGui()
{
    std::shared_ptr<cg::SpriteComponent> gui =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("gui", COREWAR_BACKGROUND));
    gui->setPosition(sf::Vector2f(31, 28));

    std::shared_ptr<cg::SpriteComponent> settingsButton =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("settings", SETTINGS_BUTTON));
    settingsButton->setTextureRect(sf::IntRect(0, 0, 277, 90));
    settingsButton->setPosition(sf::Vector2f(58, 50));

    std::shared_ptr<cg::SpriteComponent> playButton =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("play", PLAY_BUTTON));

    playButton->setTextureRect(sf::IntRect(0, 0, 87, 90));
    playButton->setPosition(sf::Vector2f(1680, 50));

    std::shared_ptr<cg::SpriteComponent> nextButton =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("nextcycle", NEXT_CYCLE_BUTTON));

    nextButton->setTextureRect(sf::IntRect(0, 0, 87, 90));
    nextButton->setPosition(sf::Vector2f(1780, 50));

    this->addComponent(gui);
    this->addComponent(settingsButton);
    this->addComponent(playButton);
    this->addComponent(nextButton);

    std::shared_ptr<cg::TextComponent> instruction =
        std::make_shared<cg::TextComponent>(cg::TextComponent(
            "currInstruction", "No instruction", DIOGO_FONT_PATH));

    instruction->setPosition(sf::Vector2f(1500, 110));
    instruction->setOrigin(
        sf::Vector2f(instruction->getLocalBounds().width / 2,
            instruction->getLocalBounds().height / 2));
    instruction->setCharacterSize(17);
    instruction->setFillColor(sf::Color::White);
    this->addComponent(instruction);
}

void cg::GameScene::onInit(sf::RenderWindow &window)
{
    this->loadGui();

    std::shared_ptr<cg::SpriteComponent> cursor =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("Cursor", CURSOR));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    int k = 0;
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 96; j++, k++) {
            char byteStr[3];
            sprintf(byteStr, "%02X", corewar->vm->fields[k].value);
            std::shared_ptr<cg::TextComponent> byte =
                std::make_shared<cg::TextComponent>(cg::TextComponent(
                    "byte " + std::to_string(k), byteStr, DIOGO_FONT_PATH));

            byte->setCharacterSize(8);
            byte->setOutlineColor(sf::Color::White);
            byte->setPosition(
                sf::Vector2f(400 + (j * 15.5), 200 + (i * 13.2)));
            byte->setFillColor(
                this->getTeamColor(corewar->vm->fields[k].owner_id, false));
            byte->setOrigin(sf::Vector2f(byte->getLocalBounds().width / 2,
                byte->getLocalBounds().height / 2));
            this->addComponent(byte);
            this->bytesComponent.insert(this->bytesComponent.end(), byte);
        }
    }
    this->fillChampionsProperties();
    this->fillVmProperties();
    this->addComponent(cursor);
}

int cg::GameScene::onUpdate(sf::RenderWindow &window)
{
    static int PlayState = 0;
    // GET cursor
    std::shared_ptr<cg::SpriteComponent> cursor =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Cursor"));

    // UPDATE CURSOR
    cursor->setPosition(
        sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    std::shared_ptr<cg::SpriteComponent> settingsButton =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("settings"));

    std::shared_ptr<cg::SpriteComponent> playButton =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("play"));

    std::shared_ptr<cg::SpriteComponent> nextButton =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("nextcycle"));

    if (this->isComponentHovered(settingsButton)) {
        settingsButton->setTextureRect(sf::IntRect(277, 0, 277, 90));
        if (MousePress)
            return 1;
    } else
        settingsButton->setTextureRect(sf::IntRect(0, 0, 277, 90));

    if (this->isComponentHovered(playButton) && PlayState == 0) {
        playButton->setTextureRect(sf::IntRect(87, 0, 87, 90));
        if (MousePress) {
            PlayState = 1;
            MousePress = false;
        }
    } else if (PlayState == 0)
        playButton->setTextureRect(sf::IntRect(0, 0, 87, 90));

    if (this->isComponentHovered(playButton) && PlayState == 1) {
        playButton->setTextureRect(sf::IntRect(261, 0, 87, 90));
        if (MousePress) {
            PlayState = 0;
            MousePress = false;
        }
    } else if (PlayState == 1)
        playButton->setTextureRect(sf::IntRect(174, 0, 87, 90));

    if (this->isComponentHovered(nextButton))
        nextButton->setTextureRect(sf::IntRect(87, 0, 87, 90));
    else
        nextButton->setTextureRect(sf::IntRect(0, 0, 87, 90));

    std::shared_ptr<cg::TextComponent> cycleCountText =
        std::dynamic_pointer_cast<cg::TextComponent>(
            this->getComponentFromTag("cycle count prop"));

    cycleCountText->setString(std::to_string(corewar->vm->cycles));

    int k = 0;
    for (auto &byte : this->bytesComponent) {
        char byteStr[3];
        sprintf(byteStr, "%02X", corewar->vm->fields[k].value);
        std::shared_ptr<cg::TextComponent> byteCompo =
            std::dynamic_pointer_cast<cg::TextComponent>(this->getComponentFromTag(
                "byte " + std::to_string(k)));

        byteCompo->setString(byteStr);
        byteCompo->setOutlineColor(sf::Color::White);
        if (byteCompo != this->selectedByte)
            byteCompo->setFillColor(
            this->getTeamColor(corewar->vm->fields[k].owner_id, false));
        k++;

        static float value = 0;
        value += this->getDt();

        if (this->isPlaying && value > 50) {
            next_cycle(this->corewar);
            value = 0;
        }
    }
    process_t *process = corewar->vm->processes;

    while (process) {
        std::shared_ptr<cg::TextComponent> byteCompo =
            std::dynamic_pointer_cast<cg::TextComponent>(this->getComponentFromTag(
                "byte " + std::to_string(process->pos)));
        if (!byteCompo)
            continue;
        byteCompo->setFillColor(getTeamColor(corewar->vm->fields[process->pos].owner_id, true));
        process = process->next;
    }
    return -1;
}
void cg::GameScene::onDelete()
{
}

int cg::GameScene::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            exit(0);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (this->isComponentHovered(this->getComponentFromTag("nextcycle"))) {
            next_cycle(corewar);
            return -1;
        }
        if (this->isComponentHovered(this->getComponentFromTag("play"))) {
            this->isPlaying = !this->isPlaying;
            return -1;
        }
        if (selectedByte != nullptr) {
            selectedByte->setFillColor(this->getTeamColor(
                corewar->vm
                    ->fields[stoi(selectedByte->getTag().substr(
                        5, strlen(selectedByte->getTag().c_str())))]
                    .owner_id, false));
            selectedByte = nullptr;
        }
        for (const auto &item : getComponents()) {
            if (item.first.find("byte ") != std::string::npos
                && this->isComponentHovered(item.second)) {
                std::dynamic_pointer_cast<cg::TextComponent>(item.second)
                    ->setFillColor(sf::Color::Red);
                selectedByte =
                    std::dynamic_pointer_cast<cg::TextComponent>(item.second);

                int cell = stoi(item.second->getTag().substr(
                    5, strlen(item.second->getTag().c_str())));
                instruction_t *instruction =
                    get_instruction(corewar->vm->fields, cell);

                std::shared_ptr<cg::TextComponent> currInstruction =
                    std::dynamic_pointer_cast<cg::TextComponent>(
                        this->getComponentFromTag("currInstruction"));

                if (!instruction) {
                    currInstruction->setString("Invalid");
                    break;
                }
                currInstruction->setString(instruction->name);
                for (int i = 0; i < 3 && instruction->params_type[i]; i++) {
                    currInstruction->setString(currInstruction->getString()
                        + " " + (instruction->params_type[i] == 1 ? "r" : "%")
                        + std::to_string(instruction->params[i])
                        + ((i + 1) >= 3 || !instruction->params_type[i + 1]
                                ? ""
                                : ", "));
                }
                break;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
        MousePress = true;
    else
        MousePress = false;
    return -1;
}

void cg::GameScene::onChange()
{
}