#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief main
/// \param argc
/// \param argv
/// \return 
///
#include <fstream>
#include <iostream>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int variable_synapse_index_counter=10100;  // 0
long long variable_error;
int var ;
using namespace std;
QString Nazvaniye_fayla_s_neyronami_i_signalom;
/// 
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "bez_1_GUI" << std::endl;  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Сначала укажем какой файл с нейронами подстроить. По-хорошему потом его надо считывать от функции решения 2
     Nazvaniye_fayla_s_neyronami_i_signalom = QFileDialog::getOpenFileName(this,
       tr("Открыть файл neyroni_i_signal.txt без 1 который надо подстроить."), 
       "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/", tr("Text Files (*.txt)"));
    
   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор ///////////////////////////////////////////////////////////////////////////////////////
//  std::vector<unsigned long long>  list_of_neurons(250, 0);
/// 
    std::ifstream is(
        
     //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0/neyroni_i_signal.txt"
    Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str() 
        // FIXME: тут же файлы надо менять!
        //NOTE: сигналы 1; считывание в вектор нейронов и сигналов из файла (НАДО Менять для подстройки)
        );
        std::vector<unsigned long long> list_of_neurons(250, 0ULL);
    std::istream_iterator<unsigned long long> start(is), end;  // end
   // std::vector<unsigned long long> list_of_neurons(start, end);   // end
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///////////////////////////////////// загрузка синапсов из файла в вектор //////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is2(
  //  "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt-4"
  "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    );
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       variable_error     =   1073741824-list_of_neurons[200] ;
    
    if  ( variable_error <=0)
    {
        
        std::cout << "Программа считает что это 1." << std::endl;
    }
    else {        std::cout << "Программа считает что это не 1." << std::endl;   goto d;  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // если ошибки нет то на выход
    if (variable_error>=0) // тут видимо надо менять на если ошибка = или > то на выход то есть ошибка пропадает если становится > 0
        // Если это 1 то надо стремиться чтоб ошибка стала меньше 0 а если не 1 то надо стремиться чтоб ошибка стала больше 0?
        
        goto d;
    std::cout << "variable_error = " << variable_error<< std::endl;
    std::cout << "Variable error = 1073741824-list_of_neurons[200] = " << 1073741824-list_of_neurons[200]<< std::endl;
    std::cout << "list_of_neurons[200]  = " << list_of_neurons[200]  << std::endl;
b:
    ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
// NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            // sigpe арифметическое исключение: (СИНАПСЫ бЫЛИ 0 ДЕление на 0)
            list_of_neurons[var]=list_of_neurons[var]-  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]); // + на -   
        } // вычитаем нейроны
    }
    
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] - (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
    }
   variable_error     = 1073741824-  list_of_neurons[200] ; // WARNING: изменение
  //  variable_error     = list_of_neurons[200]-1073741824 ;
    
     std::cout << "variable_error = " << variable_error<< std::endl;
    if (variable_error>=0) // to the exit
        // goto c;
        goto d;
    if (list_of_synapses[10100]==1) // to the exit если последний список максимальный возможный то выходим; это видимо при +1
    // 2147483646 на 1 как было
    {
        std::cout <<
           // "The values of all synapses are maximum and equal to 2147483646."
                  "The values of all synapses are minimal and equal to 1."
                  << std::endl;
        goto d;
    }
e:             // TODO: тут видимо менять условия - края и не -1 а +1
    if (list_of_synapses[variable_synapse_index_counter] < 2147483646 ) // < 2147483646 или > 1
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]+1;  // +1 или -1
    
    if (list_of_synapses[variable_synapse_index_counter] ==2147483646) //  == 2147483646 или 1
    {
        variable_synapse_index_counter = variable_synapse_index_counter-1;
                                         //+1; 
        goto e;
    }
    if (variable_synapse_index_counter>0//<10100
        )
        variable_synapse_index_counter=variable_synapse_index_counter-1;
        // с конца прибавляем по 1: int variable_synapse_index_counter=10100;
                                         //+1;  // TODO: поменять начальный индекс на максимум и вычитать по 1
    else
        variable_synapse_index_counter=10100;
            //=0;
    goto b;
d:
// записываем вектор синапсов в файл
    fstream file;
    file.open(
       "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    ,ios_base::out);
    
    vector<unsigned long long>::iterator itr;
    
    for(itr=list_of_synapses.begin();itr!=list_of_synapses.end();itr++)
    {
        file<<*itr<<endl;
    }
    
    file.close();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "The error has disappeared. Variable error = " << variable_error<< ". Это выход. "<<std::endl;
            std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if  ( variable_error <=0)
            {
                
                std::cout << "Программа считает что это 1." << std::endl;
            }
            else {        std::cout << "Программа считает что это не 1." << std::endl;    } //  меняем на это не 1
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                /// тут надо записать сигнал и нейроны в файл
//########################################################################################################

// Создаем файл для записи вектора
QString fileName = Nazvaniye_fayla_s_neyronami_i_signalom; // имя файла для записи вектора
QFile file2(fileName);
if (file2.open(QFile::WriteOnly | QFile::Text)) {
    QTextStream out(&file2);
    for (unsigned long long neuron : list_of_neurons) {
        out << neuron << "\n";
    }
    file2.close();
} else {
    qDebug() << "Error: unable to open file for writing";
}

// Записываем название файла в другой файл
QString configFile = "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/noveyshie_neyrony_i_signal.txt";
QFile configFileHandle(configFile);
if (configFileHandle.open(QFile::WriteOnly | QFile::Text)) {
    QTextStream out(&configFileHandle);
    out << fileName << "\n";
    configFileHandle.close();
} else {
    qDebug() << "Error: unable to open config file for writing";
}
//########################################################################################################
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                fstream file3;
//                file3.open(
//                    // NOTE: сигналы 2
//                                        // 3:
//                    // FIXME: файлы надо менять!
//                    Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str() 
//                 //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0-2/neurons_and_signal.txt"
//                   ,ios_base::out);
                
//                vector<unsigned long long>::iterator itr2;
                
//for (itr2=list_of_neurons.begin(); itr2 != list_of_neurons.begin() + 250; ++itr2) {
//    file3 << *itr2 << endl;
//}
                
//             file3.close();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                ///  
                QProcess().execute("/home/viktor/my_scripts_2/zvuk.sh");                
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
////////////////////// eND Dialog ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// /      
}

Dialog::~Dialog()
{
    delete ui;
}

