#include "figures.hpp"
#include "file.hpp" 

void test_figure(){
    Figure * tab_figures[4] = {new Rectangle(2, 5),new Carre(5),new TriangleEquilateral(98),new Cercle(6, "Rouge")};
    for( int i = 0 ; i < 4 ; i++ ){
        tab_figures[i]->afficherCaracteristiques();
        cout << "Périmètre : " << tab_figures[i]->perimetre() << endl;
    }
    cout << "Nombre de figures crées : " << tab_figures[3]->getCount() << endl;
}

void test_files() { 
  Cellule<int> cel(new int(5), NULL, NULL); 
  File<int> file_vide; 
  File<int> file(new int(5)); 
} 

int main() {
    test_figure();
    test_files(); 
    return 0;
}
