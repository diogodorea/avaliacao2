#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		if (d1.ano < d2.ano){
			return -1;
		}else if(d1.ano < d2.ano){
			return 1;
		}else {
			if (d1.mes < d2.mes){
				return -1;
			}else if( d1.mes > d2.mes){
				return 1;
			}else {
				if(d1.dia < d2.dia){
					return -1;
				} else if( d1.dia > d2.dia){
					return 1;
				}else {
					return 0;
				}
			}
		}
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
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
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int nEntradas;
		cout << "Quantos nomes para acrescentar a lista?" << endl;
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
			cout << "Entrada invalida." << endl;
		}
	}
	
	void mostraMediana() {
		sort(lista.begin(),lista.end());
		int n = lista.size();
		if (n%2 != 0){
			cout << "Mediana encontrada: " << lista[n/2] << endl;
		} else {
			cout << "Mediana encontrada: " << lista[n/2-1] << endl;
		}
	}
	
	void mostraMenor() {
		cout << "Menor valor...(ou seja primeiro nome ordem alfabetica):" << endl;
		cout << lista.front() << endl;
	}
	
	void mostraMaior() {
		cout << "Maior valor...(ou seja ultimo nome ordem alfabetica):" << endl;
		cout << lista.back() << endl << endl;
	}
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl << endl;
	}
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:

	void entradaDeDados() {
		int qtd_salarios, n;
		double aux_salario, aux;
		bool verifica = false, trocou;

		cout << "Informe a quantidade de salarios";
		cin >> qtd_salarios;
		
		do{
		if(qtd_salarios >= 1){
		for(int i=0; i < qtd_salarios ; i++){
			cout << "Informe o salario";
			cin >> aux_salario;
			lista.push_back(aux_salario);
			verifica = true;
		}
			}else{
				cout << "Informe um valor maior que 0";
			}
            n = lista.size() - 1;
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

		}while(verifica != true);

		
	}
			
	void mostraMediana() {

		int aux_cont;
		if(lista.size() % 2 != 0){
			aux_cont = lista.size()/2;
		for(int i=0; i < lista.size(); i++){
			if(lista[i] == lista[aux_cont]){
            cout << "A mediana e: " << lista[i]<< endl;
			}
		}
	}
	}
	
	void mostraMenor() {
	
	}
	
	void mostraMaior() {
	}
	
	
};


class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
			
	void entradaDeDados() {
		int qtd_idades; 
		cout << "Informe a quantidade de elementos que existirao na lista de idade: " ;
		cin >> qtd_idades;

		for( int i=0; i<qtd_idades; i++){
			int idade; 
			cout << "Digite a idade " << i+1 << ":"<<endl;
			while (!(cin >> idade) || idade < 0 || idade > 150){
				cout << " Idade invalida!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			lista.push_back(idade);
		}
		
	}
	
	void mostraMediana() {
		if (lista.empty()) {
        cout << "Não há termos na lista de idade!" << endl;
    } else {
        sort(lista.begin(), lista.end());

        int n = lista.size();
        double mediana;

        if (n % 2 == 1) {
            mediana = lista[n / 2];
        } else {
            mediana = (lista[n / 2 - 1] + lista[n / 2]) / 2.0;
        }

        cout << "A mediana da lista de idades eh: " << mediana << endl;
    	}
	}
	
	void mostraMenor() {
		if(lista.empty()){
			cout << "Não há termos na lista de idade !" << endl;
		} else {
			int idade_menor = *min_element(lista.begin(), lista.end());
			cout << "A menor idade: " << idade_menor << endl;
		}
	}

	void mostraMaior() {
		if(lista.empty()){
			cout << "Não há termos na lista de idade !" << endl;
		} else {
			int idade_maior = *max_element(lista.begin(), lista.end());
			cout << "A maior idade: " << idade_maior << endl;
		
		}
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

