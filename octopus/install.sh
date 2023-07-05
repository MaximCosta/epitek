#!/bin/bash

# Couleurs
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

# Installation de Python et de pip
echo -e "${YELLOW}Installation de Python et de pip...${NC}"
sudo apt-get install -y python3 python3-pip

# Installation des modules Python nécessaires pour Ansible
echo -e "${YELLOW}Installation des modules Python nécessaires pour Ansible...${NC}"
sudo pip3 install ansible

# Installation de Git
echo -e "${YELLOW}Installation de Git...${NC}"
sudo apt-get install -y git

# Installation de package community.postgresql
echo -e "${YELLOW}Installation de package community.postgresql...${NC}"
ansible-galaxy collection install community.postgresql

echo -e "${GREEN}Le script s'est terminé avec succès !${NC}"

echo -e "\n\n"
echo -e "${YELLOW}Veuillez lancer la commande suivante pour lancer le playbook :${NC}"
echo -e "   $ ${YELLOW}export${NC} ANSIBLE_VAULT_PASSWORD_FILE=/tmp/.vault_pass"
echo -e "   $ ${GREEN}echo${NC} verySecretPassword ${YELLOW}>${NC} /tmp/.vault_pass"
echo -e "   $ ${GREEN}ansible-playbook${NC} -i ${YELLOW}<${NC}your_file${YELLOW}>${NC} playbook.yml"
