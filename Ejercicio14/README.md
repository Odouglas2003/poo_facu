Ejercicio 14
Diseñar un login con QGridLayout.
Usar asteriscos para la clave.
Detectar enter para simular la pulsación del botón.
Definir la clase Formulario que será un QWidget
Formulario tendrá QLabels y QLineEdits para Legajo, Nombre y Apellido, y un QPushButton
Si la clave ingresada es admin:1111, se cierra Login y se muestra Formulario
Si se ingresa otra clave se borrará el texto del QLineEdit de la clave.

(continuación):
Publicar en la ventana de Login, la temperatura actual en la Ciudad de Córdoba. Usar alguna API disponible.
Agregar un método en Login que permita mostrar u ocultar la información de la temperatura.
Además que la ventana de Login tenga como background una imagen descargada de interner, centrada y adaptada en tamaño, sin deformar su aspecto y que permita al usuario que modifique el tamaño del Login y que se siga viendo correctamente la imagen.
Agregar un método en Login que permita indicar la URL de la imagen que se mostrará en el background. En caso que nunca se invoque a este método, ninguna imagen se mostrará.

(continuación):
Agregar la siguiente característica a Login: Si el usuario falla 3 veces la clave, bloquear por 5 minutos a ese usuario.

(continuación):
Este ejercicio viene de la clase 5, 7 y 8.
Incorporar la validación de usuarios con QSLite.
Todo lo que se haga con la base de datos, que se encuentre en la clase AdminDB
Pueden utilizar SQLiteStudio (https://sqlitestudio.pl) o similar.

(continuación):
Este ejercicio viene de la clase 5, 7, 8 y 12.
Implementar en AdminDB el uso de MD5 para las claves de los usuarios.