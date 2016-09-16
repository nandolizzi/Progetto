# README
*****************************************
##### Esame di *Programmazione dei sistemi di calcolo*

**Nando Frantellizzi, mat. 1386197**
*****************************************

Il programma sviluppato si occupa del calcolo del percorso di un robot in grado di muoversi in maniera precisa di un passo alla volta.

Il programma richiede come argomento un file *.pgm* (e.g. la mappa) rappresentante un'area di **60m x 80m** suddivisa in celle di **0,1m**. Dopo aver ricevuto in ingresso le coordinate della posizione di partenza e di arrivo elabora il percorso più breve per consentire al robot di muoversi tra le due posizioni evitando eventuali ostacoli.

Il programma restituisce un nuovo file *.pgm* copia della mappa originale, sulla quale sarà tracciato il percorso che il robot dovrà eseguire per raggiungere il **goal** dalla posizione di **start**.

## Uso
Compilare il file dai file sorgente utilizzando CMake:
```bash
mkdir build
cd build
cmake ..
make
```
L'eseguibile verrà creato della cartella `<project_folder>/bin`. Per il caricamento del file .pgm inserire il percorso relativo alla cartella bin. Ad esempio:
```
cd <project_folder>/bin
./generate_robot_path <path_to_map>/map_name.pgm

```
