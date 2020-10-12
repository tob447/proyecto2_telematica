# **PCAM Game Of Life Paralelo**

## **Partition y Communication**
Para nuestras primeras dos tareas podemos identificar dos ciclos interiores. El primer ciclo T1 corre 3 x ancho del tablero x altura del tablero. La segunda tarea T2 ancho del tablero x altura tablero
<img src="pcamimages\Capture.PNG" alt="Dos primeros loop internos"/>

Nuestra T3 es un ciclo que se ejecuta las veces del ancho del tablero de juego osea x veces. Nuestra T4 se ejecuta 1 vez por cada generacion de celula , en este caso el codigo solo se haciendo una generacion de celula , por lo tanto se ejecuta una sola vez

<img src="pcamimages\Capture2.PNG" alt="Dos loops externos"/>

Por ultimo tenemos a T0 
<img src="pcamimages\Capture3.PNG" alt="Dos loops externos"/>

### **Resumen de Tareas y cuantas veces se ejecuta**
T1 = corre 3 x ancho del tablero x altura del tablero
T2 = ancho del tablero x altura tablero
T3 = ancho del tablero
T4 = 1 vez
### **Arbol Particion Funcional**
<img src="pcamimages\diagramas\Diapositiva1.PNG" alt="Dos loops externos"/>

### **Arbol Particion Datos**
<img src="pcamimages\diagramas\Diapositiva2.PNG" alt="Dos loops externos"/>


## **Agglomeration**

## **Mapping**