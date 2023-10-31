#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<cmath>
#include <ctime>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	static int compara(Data d1, Data d2) { 
		
        tm data1 = {};

        data1.tm_mday = d1.dia;
        data1.tm_mon = d1.mes;
        data1.tm_year = d1.ano -1900;
        mktime(&data1);
        
        tm data2 = {};

        data2.tm_mday = d2.dia;
        data2.tm_mon = d2.mes;
        data2.tm_year = d2.ano -1900;
        mktime(&data2);

        if(difftime(mktime(&data1), mktime(&data2)) > 0){
            return +1;
        }else if(difftime(mktime(&data1), mktime(&data2)) < 0){
            return -1;
        }else{
            return 0;
        }
	}

	Data (int _dia, int _mes, int _ano) {
		this->dia = _dia;
		this->mes = _mes;
		this->ano = _ano;
	}

	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem()=0;
	virtual void mostrarNElementos()=0;
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	void mostrarNElementos() override {

		listarEmOrdem();
		 int N;
   		 cout << "Quantos elementos deseja visualizar na lista de nomes?" << endl;
    	 cin >> N;

    	if (N >= 0 && N <= lista.size()) {
        cout << "--Os primeiros " << N << " elementos da lista de nomes sao--" << endl;
        for (int i = 0; i < N; i++) {
            cout << lista[i] << endl;
        }
    } else {
        cout << "Número invalido de elementos." << endl;
    	}
	}


		void listarEmOrdem() override{
			sort(lista.begin(), lista.end());
			cout << "-- Os nomes em ordem alfabetica sao--"<<endl;
             for (const string &nome : lista) {
             cout << nome << endl;
        }
	}

	void entradaDeDados() {
		int nEntradas;
		cout << "Quantos nomes para acrescentar a lista? " << endl;
		cin >> nEntradas;

		if (nEntradas >=1){
			cin.ignore();
			for (int i=0 ; i < nEntradas; i++){
				string  nome;
				cout << "Informe o nome: " << (i+1) << ":" << endl;
				getline(cin, nome);
				lista.push_back(nome);
			}
		} else{
			cout << "Entrada invalida. " << endl;
		}
		cout << endl ;
	}
	
	void mostraMediana() {
		listarEmOrdem();
		int n = lista.size();
		if (n%2 != 0){
			cout << "--Mediana encontrada eh-- " << endl << lista[n/2] << endl;
		} else {
			cout << "--Mediana encontrada eh--" << endl << lista[n/2-1] << endl;
		}
	}
	
	void mostraMenor() {
		cout << "--Menor valor...(ou seja, primeiro nome ordem alfabetica)--" << endl;
		cout << lista.front() << endl;
	}
	
	void mostraMaior() {
		cout << "--Maior valor...(ou seja, ultimo nome ordem alfabetica)--" << endl;
		cout << lista.back() << endl << endl;
	}
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		void mostrarNElementos() override {

			listarEmOrdem();
		 int N;
   		 cout << "Quantos elementos deseja visualizar na lista de Datas?" << endl;
    	 cin >> N;
		
    	if (N >= 0 && N <= lista.size()) {
        cout << "--Os primeiros " << N << " elementos da lista de datas sao-- " << endl;
        for (int i = 0; i < N; i++) {
            cout << lista[i].toString() << endl;
        }
    } else {
        cout << "Número inválido de elementos." << endl;
    	}

		}

	void listarEmOrdem() override {

		bool trocou;
		
		do {
            trocou = false;
            for (int i = 0; i < lista.size()-1; i++) {
                    
                    int compara = Data::compara(lista[i], lista[i+1]);

                if (compara == 1) {
                    Data aux(3,3,3);
                    aux = lista[i];
                    lista[i] = lista[i + 1];
                    lista[i + 1] = aux;
                    trocou = true;
                }
            }
        } while (trocou);
	}

	void entradaDeDados() {
		int nEntradas;
		cout << "Quantas datas para acrescentar a lista?" << endl;
		cin >> nEntradas;

		if (nEntradas >=1){
			cin.ignore();
			for (int i=0 ; i < nEntradas; i++){
				int auxDia, auxMes, AuxAno;
				cout << "Informe o dia para a data " << (i+1) << ":" << endl;
				cin >> auxDia;
				cout << "Informe o mes para a data " << (i+1) << ":" << endl;
				cin >> auxMes;
				cout << "Informe o ano para a data " << (i+1) << ":" << endl;
				cin >> AuxAno;
				Data data(auxDia, auxMes, AuxAno);
				lista.push_back(data);
			}
		} else{
			cout << "Entrada invalida." << endl;
		}
		cout << endl ;
	}
	
	void mostraMediana() {
		listarEmOrdem();

		int n = lista.size();
		if (n%2 != 0){
			cout << "Mediana encontrada: " << lista[n/2].toString() << endl;
		} else {
			cout << "Mediana encontrada: " << lista[n/2-1].toString() << endl;
		}
	}
	
	void mostraMenor() {
		cout << "--Primeira data ordem cronologica--" << endl;
		cout << lista.front().toString() << endl;
	}
	void mostraMaior() {
		cout << "--Ultima data ordem cronologica--" << endl;
		cout << lista.back().toString() << endl << endl;
	}
	
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:


	void entradaDeDados(){
		int qtd_salarios;
		double aux_salario;
		bool verifica = false;

		
	do {
    cout << "Informe a quantidade de salarios: " << endl;
    cin >> qtd_salarios;

    if (!cin.fail() && qtd_salarios >= 1) {
        verifica = true; 
        for (int i = 0; i < qtd_salarios; i++) {
            cout << "Informe o salario " << i + 1 << ": ";
            cin >> aux_salario;
            lista.push_back(aux_salario);
        }
    } else {
        cout << "Informe um valor numerico valido e maior ou igual a 1." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

} while (!verifica);
 	cout << endl ;
	}

	void listarEmOrdem() override{
 		bool trocou;
		double aux;
		int n = lista.size() - 1;
		do {
            trocou = false;
            for (int j = 0; j < n; j++) {
                if (lista[j] > lista[j + 1]) {
                    aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                    trocou = true;
                }
            }
            n--;
        } while (trocou);
	}

	void mostrarNElementos() override {
		
		listarEmOrdem();
	 	int Num_elementos;
        cout << "Digite o numero de elementos que deseja exibir da lista de salarios: ";
        cin >> Num_elementos;
		cout << endl << endl;

        cout << "--Os primeiros " << Num_elementos << " elementos da lista de salarios em ordem crescente sao--" << endl;
        int contador = 0;
        for (int salario : lista) {
            cout<<salario << " ";
            contador++;
            if (contador >= Num_elementos) {
                break;
            }
        }
        cout << endl<< endl;
    }

	void mostraMediana() {

		listarEmOrdem();
		int aux_cont, aux_cont1, aux_cont2;
		if(lista.size() % 2 != 0){
			aux_cont = lista.size()/2;
		for(int i=0; i < lista.size(); i++){
			if(lista[i] == lista[aux_cont]){
            cout << "--A mediana do salario eh-- " << endl << lista[i]<< endl;
        
			}
		}
	}else {
		 aux_cont1 = (lista.size()/2)-1;
		 aux_cont2 = (lista.size()/2);
		 cout << "--A mediana do salario eh-- " <<endl<< (lista[aux_cont1] + lista[aux_cont2]) /2 << endl;
	  }
	}
	
	void mostraMenor() {
	double num_menor = 99999999;

		for(int i=0; i < lista.size(); i++){
			if(lista[i] < num_menor ){
				num_menor = lista[i];
			}
		}
		  cout << "--O menor dos salarios eh-- " << endl<< num_menor << endl;
	}
	
	void mostraMaior() {
		double num_maior = 1;

			for(int i=0; i < lista.size(); i++){
				if(lista[i] > num_maior){
					num_maior = lista[i];
				}
			}
		cout << "--O maior dos salarios eh-- " << endl << num_maior << endl<< endl;
	}
	
	
};


class ListaIdades : public Lista {
	vector<int> lista;
	
	public:

	void listarEmOrdem() override{
		
		if (lista.empty()) {
            cout << "A lista de idades esta vazia!" << endl;
        } else {
            sort(lista.begin(), lista.end());
		}
	}
	 		
	void entradaDeDados() {
		int qtd_idades; 
		cout << "Informe a quantidade de elementos que existirao na lista de idade: " ;
		cin >> qtd_idades;

		for( int i=0; i<qtd_idades; i++){
			int idade; 
			cout << "Digite a idade " << i+1 << ":" << endl;
			while (!(cin >> idade) || idade < 0 || idade > 150){
				cout << " Idade invalida!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
			}
			lista.push_back(idade);
		}
		cout << endl ;
	}
	
	void mostraMediana() {
		listarEmOrdem();

		if (lista.empty()) {
        cout << "Nao ha termos na lista de idade!" << endl;
    } else {

        int n = lista.size();
        double mediana;

        if (n % 2 == 1) {
            mediana = lista[n / 2];
        } else {
            mediana = (lista[n / 2 - 1] + lista[n / 2]) / 2.0;
        }

        cout << "--A mediana da lista de idades--" << endl << mediana << endl;
    	}
	}
	
	void mostraMenor() {
		if(lista.empty()){
			cout << "Nao ha termos na lista de idade! " << endl;
		} else {
			int idade_menor = *min_element(lista.begin(), lista.end());
			cout << "--A menor idade--" << endl << idade_menor << endl;
		}
	}

	void mostraMaior() {
		if(lista.empty()){
			cout << "Nao ha termos na lista de idade! " << endl;
		} else {
			int idade_maior = *max_element(lista.begin(), lista.end());
			cout << "--A maior idade--" << endl << idade_maior << endl<< endl;
		}
	}

	void mostrarNElementos() override {

		listarEmOrdem();
        if (lista.empty()) {
            cout << "A lista de idades esta vazia!" << endl;
            return;
        }

        int N;
        cout << "Digite o numero de idades que deseja exibir: ";
        cin >> N;
		cout << endl << endl;

        cout << "--Os primeiros " << N << " elementos da lista de idades em ordem crescente sao--" << endl;
        int contador = 0;
        for (int idade : lista) {
            cout<<idade << " ";
            contador++;
            if (contador >= N) {
                break;
            }
        }
        cout << endl<< endl;
    }

};

int main () {
	vector<Lista*> listaDeListas;
	

	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	//listaIdades.mostrarNElementos();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostrarNElementos();
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
