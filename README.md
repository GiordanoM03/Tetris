# TETRIS

Progetto del corso di Programmazione (12 CFU) dell'anno accademico 2023/2024 presso l'Universita' degli studi di Bologna

## Struttura Gioco
Il gioco viene diviso in 3 sezioni:

1. I blocchi di gioco (tetramini)
2. La schermata di gioco
3. La schermata iniziale

### 1. Tetramini
#### Grafica
I tetramini vengono rapresentati sullo schermo come un insieme di 4 "[]" che danno la forma del tetramino, mentre sui file utilizzati per rappresentare le forme viene usato il binario, dove 1 rappresenta il "[]", mentre 0 rappresenta l'assenza dell'elemento. Il perché della scelta viene spiegato nella sezione "**Implementazione**"
I file grafici si trovano nella cartella [Tetramini](https://github.com/GiordanoM03/Tetris) presente su GitHub.  
I tetramini avranno anche un colore, per evitare di confonderli quando saranno tutti impilati.

#### Implementazione
La prima scelta d'implementazione legata ai tetramini è quella di utilizzare dei file contenenti i "disegni" dei tetramini in formato binario, cioè avere lo 0 che indica il vuoto e 1 che indica la presenta del tetramino. Questa scelta nasce dalla necessità di trovare un modo per controllare il contatto tra i vari blocchi nella matrice di gioco.  
Abbiamo implementato tutti e 7 i tetramini del gioco originale, e per fare in modo che ogni volta uscisse un tetramino diverso, ci siamo serviti di 2 funzioni random, una che sceglie un numero fino a 7 e l'altra che sceglie un numero fino a 4. Il compito della prima funzione è quello di scegliere il tetramino da lanciare in gioco tra quelli disponibili, quello della seconda invece è di appliare una rotazione di 90° in senso orario per x volte, tale che x sia il numero uscito dalla funzione. In questo modo è molto probabile di avere sempre tetramini diversi. 
L'altra scelta implementativa è legata alla grafica del gioco, dove, per avere un gioco più interessante graficamente, andiamo a cambiare l'elemento grafico. Quello che facciamo e andare a cambiare il valore 1 con la stringa "[]", così da avere dei tetramini graficamente "belli".


### 2. Schermata di Gioco
#### Grafica
La grafica della schermata di gioco è ispirata sia alla proposta della schermata presente nella presentazione delle specifiche del progetto e alla schermata del gioco Tetris.  
Ciò significa che:  
- La zona di gioco, sulla destra dello schermo, è delimitata da blocchi pieni (carattere 219 della tabella ASCII) o da una un insieme di caratteri ASCII più semplici.
- Sulla sinistra dello schermo sono presenti:
    - il livello del giocatore nel cosro della partità;
    - il suo punteggio;
    - la durata della partità;
    - il blocco successivo.

### 3. Schermata Iniziale
#### Grafica
La schermata iniziale è composta da:
- un logo con il nome del gioco composto da caratteri ASCII;
- un pulsante per iniziare una nuova partità;
- un pulsante per vedere tutti i punteggi delle partite effettuate
- il record assoluto con i dati legati alla partita;
- un recap del funzionamento dei tasti