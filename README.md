# TETRIS

Progetto del corso di Programmazione (12 CFU) dell'anno accademico 2023/2024 presso l'Universita' degli studi di Bologna

## Struttura Gioco
Il gioco viene diviso in 3 sezioni:

1. I blocchi di gioco (tetramini)
2. La schermata di gioco
3. La schermata iniziale

### 1. Tetramini
#### Grafica
I tetramini vengono rapresentati sull file grrafico come degli 0 e degli 1, dove il 0 rappresenta le parti vuote e il 1 rappresenta il valore del pezzo. La scelta di avere dei valori binari è legata alla semplificazione dell'implementazione del comportamento.
I file grafici si trovano nella cartella [Tetramini](https://github.com/GiordanoM03/Tetris) presente su GitHub.

#### Implementazione

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