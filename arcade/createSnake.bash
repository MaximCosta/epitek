##################################################################################################
# #  Ce script bash (si je puis me permettre) génère un fichier txt pour pouvoir le récupérer  # #
# #  est générer le menu home à l'aide des informations qui sont présentes dans ce fichier.    # #
##################################################################################################

echo "75 0 text (0,0,0) Snake Game" > src/Games/Snake/snake.txt
echo "5 31 text (0,0,0) [Commands]" >> src/Games/Snake/snake.txt
echo "1 33 text (0,0,0) [F5] : Previous library" >> src/Games/Snake/snake.txt
echo "1 34 text (0,0,0) [F6] : Next library" >> src/Games/Snake/snake.txt
echo "1 39 text (0,0,0) [Space] : Pause" >> src/Games/Snake/snake.txt
echo "1 40 text (0,0,0) [Suppr] : Leave" >> src/Games/Snake/snake.txt
echo "125 13 text (0,0,0) Leaderboard:" >> src/Games/Snake/snake.txt
echo "75 22 text (0,0,0) Press [^] to play !" >> src/Games/Snake/snake.txt
echo "1 36 text (0,0,0) [*] : Back to Menu" >> src/Games/Snake/snake.txt
echo "1 37 text (0,0,0) [F2] : Launch Nibbler" >> src/Games/Snake/snake.txt
echo "1 12 text (0,0,0) Username: [Press Any Letter]" >> src/Games/Snake/snake.txt
echo "" >> src/Games/Snake/snake.txt
