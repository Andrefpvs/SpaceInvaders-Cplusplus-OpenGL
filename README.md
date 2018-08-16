# SpaceInvaders-Cplusplus-OpenGL
A 3D game of Space Invaders created in C++ with the OpenGL library. Computer Graphics class project (Portuguese documentation)


### Game Readme (Portuguese):

Teclas:
Setas Esquerda e Direita - Mover a nave
Barra de Espaço - Disparar
1 - Câmara 2D (câmara inicial)
2 - Câmara 3D (isométrica)
3 - Câmara 3D (primeira-pessoa)
4 - Apagar as luzes e acender a lanterna (Câmaras 3D apenas)
5 - Acender as luzes e apagar a lanterna
6 - Modo de debug das colisões (wirespheres)
9 - Dá uma vida extra e 100 pontos (batota!)

Regras:
O objetivo é eliminar os aliens, evitando que o número de vidas da nave chegue a 0.
Um tiro basta para eliminar os aliens e a nave.
As barreiras onde a nave se pode esconder debilitam-se com cada tiro que levam, eventualmente
desaparecendo.
Se os aliens atingirem a nave, o jogador perde todas as vidas.

Como jogar:
Os ficheiros SpaceInvadersFinal.exe e glut32.dll devem estar na mesma pasta para o jogo
funcionar (mover a pasta SpaceInvaders dentro do zip para uma pasta do computador). 
Para abrir o jogo, clicar duas vezes na aplicação SpaceInvadersFinal.
O jogo abre duas janelas quando se inicia. Independentemente de se ganhar ou perder o jogo,
é necessário ser o jogador a fechar manualmente as duas janelas para terminar o jogo (no
'X' no topo superior direito das janelas)

'Bugs' conhecidos:
- Em alguns computadores, as luzes estão sempre desligadas na câmara 2D. Neste caso, pode
ser necessário mudar para uma das duas câmaras 3D para melhor visualização do jogo.
- Em alguns computadores, os tiros dos aliens "piscam" sempre que a nave do jogador se move.

Contexto:
Este projeto foi elaborado ao longo do 2º semestre do ano letivo 2012/2013 para a disciplina
de Computação Gráfica da LEIC-A (IST). A linguagem usada foi C++ com a biblioteca OpenGL.
O projecto foi avaliado com 18 valores e conta 50% da nota final da disciplina.

Créditos:
Gráficos e programação - André Fidalgo Silva, Sofia Modesto
Concept Art - Joana Natálio
