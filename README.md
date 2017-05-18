Luis Castillo

Manual de usuario para la aplicación: 
La aplicación es un Word Cloud (nube de palabras), el cual es una 
representación visual de las palabras que conforman un texto, 
en donde el tamaño es mayor para las palabras que aparecen con más frecuencia. 
Esta aplicación genera un archivo de salida .html con las palabras más 
representativas del texto ingresado. 
Debes correr el programa desde un compilador para C++. 
El programa (debe estar en una carpeta el .cpp, los .h y el archivo 
reservadas.txt) te pedirá que ingreses el nombre del archivo del cual desees 
generar el Word Cloud de tipo .txt, si el archivo está en la carpeta donde está 
el programa solo necesitarás teclear “nombreArchivo.txt”, de lo contrario 
deberás especificar la ruta de donde se encuentre el archivo deseado. 
Una vez realizado lo anterior en la consola se desplegará un mensaje diciendo 
que el Word Cloud ha sido generado; para abrir el html generado debes acudir a 
la carpeta donde está tu programa y abrir WordCloud.html. 

Manual técnico:
Para llevar a cabo el Word Cloud se utilizaron dos estructuras de datos, 
la primera fue una tabla de hash con un tamaño de 97 casillas en la cual la 
función de hashing fue la suma del código ascii de cada letra de la palabra y 
posteriormente se le aplico el método residual %97 para que cada palabra 
tuviera un lugar en la tabla. Este método fue de utilidad ya que distribuyó 
bien todas las palabras a lo largo de la tabla, sin embargo para las colisiones 
se utilizó encadenamiento externo a través de árboles de búsqueda binaria. 
Esta segunda estructura de datos utilizada fue de gran importancia ya que 
aquí es donde se ingresaban todas las palabras y se manejó un atributo llamado 
contador para ir contando las palabras repetidas. Se diseñaron métodos para 
obtener la palabra más repetida para en base a eso tomar decisiones acerca del 
tamaño de letra y para manejar el desplegado final. También cabe destacar que 
se usó lo anterior descrito para crear otra tabla de hash con las palabras 
reservadas leídas desde un archivo de texto.
