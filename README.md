# TETRIS IN C++

Questo progetto implementa il classico gioco Tetris utilizzando il linguaggio di programmazione C++ e la libreria grafica ncurses. È stato realizzato come parte del corso di Programmazione (12 CFU) presso l'Università degli Studi di Bologna per l'anno accademico 2023/2024.

Membri del Gruppo <br>
Di Vita Ivan <br>
Giordano Mael 

Descrizione del Progetto <br>
Il progetto Tetris è stato sviluppato per creare una versione giocabile del famoso gioco di puzzle Tetris. L'obiettivo principale è stato quello di implementare la logica di gioco, la gestione grafica tramite ASCII e l'interazione con l'utente.

Funzionalità del Gioco <br>
Movimento dei Tetramini:  <br>
I tetramini possono essere spostati a sinistra, a destra, possono anche essere ruotati in senso orario e antiorario. <br>
1. sinistra: key_left
2. destra: key_right
3. rotazione senso orario: key_up
4. rotazione senso antiorario: key_down
   
rilevamento delle Collisioni:  <br>
Il gioco rileva le collisioni dei tetramini con i bordi della griglia e con altri tetramini, impedendogli di spostarsi in quella direzione.  <br>
Rimozione delle Linee Complete:  <br>
Quando una linea è completamente riempita, viene rimossa e il punteggio del giocatore viene aggiornato. <br>
Il punteggio (Score) è calcolato nel seguente modo, in base alle righe eliminate: <br>
1 riga aliminata: 100 pt <br>
2 righe eliminate: 200 pt <br>
3 righe eliminate: 300 pt <br>
4 righe eliminate: 800 pt <br>
più di 4 linee eliminate: 800 pt (4 linee) + 1200 pt ogni linea extra <br>
Visualizzazione del Punteggio:  <br>
Il punteggio corrente del giocatore e il tempo trascorso vengono visualizzati sullo schermo accanto alla griglia di gioco. <br>
Salvataggio e Visualizzazione dei Punteggi: <br>
I migliori punteggi (top 5) vengono salvati e possono essere visualizzati in una schermata dedicata nel menu iniziale.  <br>


