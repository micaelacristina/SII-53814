#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd; //descriptor de fichero, usado para almacenar el valor q devuelven las fundiones
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink("FIFO");

    /* crear el FIFO */
    if (mkfifo("FIFO", 0666)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
	fd=open ("FIFO", O_RDONLY);// almacenara el valor
    if (fd<0) { 		   //si el fd es negativo, ha fallado el FIFO
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while (read(fd, buffer,sizeof(buffer))>0) { //sizeof lo utilizamos para q tengamos el numero exacto de bytes q se pueden leer (aunque la longitud total es 1024, definido por el buffer)
	printf("%s", buffer);// X5: Imprimir el texto en la pantalla
    }
    close(fd); //cerrar fifo
    unlink("FIFO"); //eliminarlo
    return(0);
}
