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
    File<int> file_vide;
    File<float> ffile;
    cout << file_vide.empty() << endl;
    cout << ffile.empty() << endl;
    ffile.push_front(new float(50.95));
    File<int> file(new int(5));
    file.push_back(new int(6));
    file.push_back(new int(7));
    file.push_front(new int(98));
    cout << (file.empty()) << ", " << file.len() << endl;
    cout << *(file.pop_front()) << endl;
    cout << *(file.pop_front()) << endl;
    cout << file.len() << endl;
    cout << *(file.pop_back()) << endl;
    cout << *(file.pop_back()) << endl;
    cout << file.empty() << endl;
}

void test_files_figures() {
    Figure *pelem;
    File<Figure> file;
    file.push_back(new Rectangle(2, 5));
    file.push_back(new Carre(5));
    file.push_back(new TriangleEquilateral(98));
    file.push_back(new Cercle(6, "Rouge"));
    file.push_back(new Cercle(19, "Violet joli"));

    int len = file.len();
    for (int i = 0; i < len; i++) {
        cout << i << endl;
        pelem = file.pop_front();
        pelem->afficherCaracteristiques();
        pelem->perimetre();
    }
}

int main() {
    test_figure();
    test_files();
    test_files_figures();
    return 0;
}
