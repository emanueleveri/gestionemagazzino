#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


double vendite()
{
    string codice,nomeprodotto,tipoProdotto;
    int numero;
    double prezzo,totale=0;
    ifstream log("log.txt");
    if(!log)
    {
        return -1;
    }else
    {
        int i=0;
        while(!log.eof())
        {//codice numero nome tipo prezzo 
            i++;
            log >> codice ;
            cout << "transazione numero " <<i << endl ; 
            log >> numero;
            log >> nomeprodotto;
            log >> tipoProdotto;
            log >> prezzo ;
            cout <<endl << "codice : " << codice << endl ;
            cout << "numero : " << numero << endl ;
            cout << "nome : " << nomeprodotto << endl ;
            cout << "tipo : " << tipoProdotto << endl ;
            cout << "prezzo : " << prezzo; 
            totale+=prezzo;
        }
        return totale;
    }
}
int vendiProdotto(string codiceVendita)
{
    fstream log("log.txt",ios::app);
    string codice,nomeprodotto,tipoProdotto;
    int numero;
    double prezzo;
    ifstream vendi("prodotti.txt");
    if(!vendi || !log )
    {
		cout << " Non riesco ad accedere ai file  " << endl 	;
		return -1;
	}else
	{
		fstream copia("prodotti2.txt",ios::app);
		if(!copia)
		{
			cout << " Non riesco ad accedere al file prodotti2.txt " << endl ;
			return -1;
		}else
		{	
            int posizione =0 ;
			string nuovocodice,nuovonome,nuovotipo;
			int nuovonumero;
			double nuovoprezzo;
            char trovato;
			while(!vendi.eof())
			{
				posizione++;
				vendi >> codice ;
                if(codice==codiceVendita)
                {
                    cout << " Trovato " << endl ;
                    vendi >> numero;
                    vendi >> nomeprodotto ;
                    vendi >> tipoProdotto ;
                    vendi >> prezzo;
                    cout << " numero " << numero << endl ;
                    cout << " nome " << nomeprodotto << endl ;
                    cout << " tipo " << tipoProdotto << endl;
                    cout << " prezzo " << prezzo << endl ; 
                    cout << " E' questo il record ? s/n" << endl ;
                    cin >> trovato; 
                    if(trovato=='s' || trovato=='S')
                    {
                        numero--;
                        copia << endl << codice << endl << numero << endl << nomeprodotto << endl << tipoProdotto << endl ;
                        copia << endl << prezzo;
                        log << endl << codice << endl << numero << endl << nomeprodotto << endl << tipoProdotto << endl ;
                        log << prezzo;
                    }//trovato = 's'
                }else//codice == codicemodifica		
                {
                    vendi >> numero;
                    vendi >> nomeprodotto ;
                    vendi >> tipoProdotto ;
                    vendi >> prezzo;
                    log << endl << codice << endl << numero << endl << nomeprodotto << endl << tipoProdotto << endl ;
                    log << prezzo;
                }
										
            }//cercaEOF
            remove("prodotti.txt");
            rename("prodotti2.txt","prodotti.txt");
            return 0;

        }//!copia
    }//!cerca
    
}
int eliminaProdotto(string codiceElimina)
{
    string codice,nomeprodotto,tipoProdotto;
    int numero;
    double prezzo;
    ifstream elimina("prodotti.txt");
    if(!elimina)
    {
		cout << " Non riesco ad accedere al file prodotti.txt " << endl 	;
		return -1;
	}else
	{
		fstream copia("prodotti2.txt",ios::app);
		if(!copia)
		{
			cout << " Non riesco ad accedere al file prodotti2.txt " << endl ;
			return -1;
		}else
		{	
            int posizione =0 ;
			string nuovocodice,nuovonome,nuovotipo;
			int nuovonumero;
			double nuovoprezzo;
            char trovato;
			while(!elimina.eof())
			{
				posizione++;
				elimina >> codice ;
                if(codice==codiceElimina)
                {
                    cout << " Trovato " << endl ;
                    elimina >> numero;
                    elimina >> nomeprodotto ;
                    elimina >> tipoProdotto ;
                    elimina >> prezzo;
                    cout << " numero " << numero << endl ;
                    cout << " nome " << nomeprodotto << endl ;
                    cout << " tipo " << tipoProdotto << endl;
                    cout << " prezzo " << prezzo << endl ; 
                    cout << " E' questo il record ? s/n" << endl ;
                    cin >> trovato; 
                    if(trovato=='s' || trovato=='S')
                    {
                        // Non copio i dati nel nuovo file quindi sono eliminati 
                    }//trovato = 's'
                }else//codice == codicemodifica		
                {
                    elimina >> numero;
                    elimina>> nomeprodotto ;
                    elimina >> tipoProdotto ;
                    elimina >> prezzo;
                    copia << endl << codice << endl << numero << endl << nomeprodotto << endl << tipoProdotto <<endl ;
                    copia << prezzo   ;
                }
										
            }//cercaEOF
            remove("prodotti.txt");
            rename("prodotti2.txt","prodotti.txt");
            return 0;

        }//!copia
    }//!cerca
}
int modificaProdotto(string codiceModifica)
{
    string codice,nomeprodotto,tipoProdotto;
    int numero;
    double prezzo;
    ifstream cerca("prodotti.txt");
    if(!cerca)
    {
		cout << " Non riesco ad accedere al file prodotti.txt " << endl 	;
		return -1;
	}else
	{
		fstream copia("prodotti2.txt",ios::app);
		if(!copia)
		{
			cout << " Non riesco ad accedere al file prodotti2.txt " << endl ;
			return -1;
		}else
		{	
            int posizione =0 ;
			string nuovocodice,nuovonome,nuovotipo;
			int nuovonumero;
			double nuovoprezzo;
            char trovato;
			while(!cerca.eof())
			{
				posizione++;
				cerca >> codice ;
                if(codice==codiceModifica)
                {
                    cout << " Trovato " << endl ;
                    cerca >> numero;
                    cerca >> nomeprodotto ;
                    cerca >> tipoProdotto ;
                    cerca >> prezzo;
                    cout << " numero " << numero << endl ;
                    cout << " nome " << nomeprodotto << endl ;
                    cout << " tipo " << tipoProdotto << endl;
                    cout << " prezzo " << prezzo << endl ; 
                    cout << " E' questo il record ? s/n" << endl ;
                    cin >> trovato; 
                    if(trovato=='s' || trovato=='S')
                    {
                        //posizioneProdotto=posizione;
                        cout << " Inserire il nuovo codice ( . per confermare il precedente )"<< endl ;
                        cin >>nuovocodice;
                        if(nuovocodice==".")
                        {
                            nuovocodice=codice;
                        }
                        cout << " Inserire il nuovo numero " << endl ;
                        cin >>nuovonumero;
                        cout << " Inserire il nuovo nome  ( . per confermare il precedente ) " << endl ;
                        cin >> nuovonome;
                        if(nuovonome==".")
                        {
                            nuovonome=nomeprodotto;
                            cout << nuovonome << endl ; 
                        }
                        cout << " Inserire il nuovo tipo  " << endl ;
                        cin >> nuovotipo;
                        if(nuovotipo==".")
                        {
                            nuovotipo=tipoProdotto;
                        }
                        cout << " Inserire il nuovo prezzo " << endl ;
                        cin >> nuovoprezzo;
                        copia <<endl <<  nuovocodice << endl ;  
                        copia << nuovonumero << endl ;
                        copia << nuovonome << endl ;
                        copia << nuovotipo << endl ; 
                        copia << nuovoprezzo  ; 
                    }//trovato = 's'
                }else//codice == codicemodifica		
                {
                    cout << " Passo " << endl ; 
                    cerca >> numero;
                    cerca >> nomeprodotto ;
                    cerca >> tipoProdotto ;
                    cerca >> prezzo;
                    copia << endl << codice << endl << numero << endl << nomeprodotto << endl << tipoProdotto <<    endl ;
                    copia << prezzo   ;
                }
										
            }//cercaEOF
            remove("prodotti.txt");
            rename("prodotti2.txt","prodotti.txt");
            return 0;
        }//!copia
    }//!cerca
}
int bancarotta()
{
    string password, read,id;
	cout << " Reinserire la password del direttore " << endl ;
	cin >> password ; 
	ifstream leggiPassword("password.txt");
	if(!leggiPassword)
	{
		return -1;
	}else
	{
		while(!leggiPassword.eof())
		{
			leggiPassword>>id;
			if(id=="direttore")
			{
				leggiPassword >> read;
			}
		}
		leggiPassword.close();	
		if(password==read)	
		{
			cout << " Operazione effettuata " << endl ; 
			remove("prodotti.txt");
            return 0;
		}else
		{
			return -2;
		}
	}
}
int aggiungiProdotto(string codice, int numero, string nomeprodotto, string tipoProdotto, double prezzo)
{
    ofstream scrivi("prodotti.txt",ios::app);	
	if(!scrivi)
	{
        return -1;
	}else
	{
		scrivi << endl << codice << endl;
	 	scrivi << numero << endl ;
		scrivi << nomeprodotto << endl ;
		scrivi << tipoProdotto << endl ;
		scrivi << prezzo ;
        return 0;
	}
}
int stampaProdotti()
{
    ifstream mostraProdotti("prodotti.txt");
    string codice,nomeprodotto,tipoProdotto;
    int numero;
    double prezzo;
	if(!mostraProdotti)
	{
        return -1;
    }else
	{
		while(!mostraProdotti.eof())
		{
			mostraProdotti >> codice ;
			mostraProdotti >> numero;
			mostraProdotti >> nomeprodotto ;
			mostraProdotti >> tipoProdotto ;
			mostraProdotti >> prezzo ;
            cout << codice <<"\t" << numero <<"\t" << nomeprodotto <<"\t" << tipoProdotto <<"\t"<<prezzo<<"\t"<<endl ;
        }
		mostraProdotti.close();
    }
}
int main()
{
	string codice, nomeprodotto, tipoProdotto;
	int numero;	
	double prezzo;
	int numeroInserito;
	string log[]={"direttore","dipendente","cliente"};
	cout << " Gestione di un magazzino : " << endl ;
	cout << " Effettuare login : " << endl ;
	for ( int i=0; i<3; i++)
	{
		cout << i+1 << "\t" << log[i] << endl ;
	}
	do
	{	
		cout << " inserire numero ... " << endl ; 
		cin >> numeroInserito;
	}while(numeroInserito > 3 || numeroInserito < 1);
	switch(numeroInserito)
	{
		case 1:
		{
			string id,password,tocheck;
			ifstream leggiPassword("password.txt");
			if(!leggiPassword)
			{
				cout << " Errore non posso verificare le password " << endl ;
				return -1;
			}else
			{
				while(!leggiPassword.eof())
				{
					leggiPassword>>id;
					if(id=="direttore")
					{
						leggiPassword >> password;
					}
				}
				leggiPassword.close();	
				retype:
				cout << " Inserire password  accesso direttore " << endl ;	
				cin >> tocheck;
				if(password==tocheck)
				{
					int scegli;
					string op[]={"mostra prodotti","modifica prodotto","elimina prodotto","aggiungi prodotto","bancarotta"};
					do
					{
						cout << " scegliere l' operazione da effettuare " << endl ;
						for ( int i=0; i< 5; i++)
						{
							cout << i+1 << "\t" << op[i] << endl ;
						}
						cin >> scegli;
					}while(scegli > 6 || scegli <1 );
					
					switch(scegli)
					{
						case 1:
						{
							int res=stampaProdotti();
                            if(res==-1)
                            {
                                cout << " Errore non riesco ad accedere al file " << endl ; 
                            }
						}break; // Fino a qua va bene 

						case 2:
						{
							string codiceModifica;
							cout << " Modifica di un prodotto " << endl ; 
							cout << " Inserire il codice del prodotto da modificare " << endl ;
							cin>>codiceModifica;
                            int res = modificaProdotto(codiceModifica);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere ad uno  o piu' file  " << endl ;
                            }else if(res==0)
                            {
                                cout << " Modifica Avvenuta " << endl ; 
                            }
							
						}break;

						case 3:
						{		
							string codiceElimina;
							cout << " Eliminazione di un prodotto " << endl ; 
							cout << " Inserire il codice del prodotto da eliminare " << endl ;
							cin>>codiceElimina;
                            int res = eliminaProdotto(codiceElimina);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere ad uno  o piu' file  " << endl ;
                            }else if(res==0)
                            {
                                cout << " Modifica Avvenuta " << endl ; 
                            }
						}break;

						case 4:
						{
							//Aggiungi un prodotto 
							string codice, nomeprodotto, tipoProdotto;
							int numero;	
							double prezzo;
							cout << " Inserire il codice " << endl ;
							cin >> codice ;
							cout << " Inserire il numero " << endl ;
							cin>>numero;
							cout << " Inserire il nome " << endl ;
							cin>>nomeprodotto;
							cout << " Inserire il tipo " << endl ;
							cin >> tipoProdotto;
							cout << " Inserire il prezzo " << endl ;
							cin>>prezzo;
                            int res=aggiungiProdotto( codice,  numero,  nomeprodotto, tipoProdotto,prezzo);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere al file " << endl ; 
                            }else if(res==0)
                            {
                                cout << " Ok ho inserito i dati ... " << endl ; 
                            }
							
						}break;

						case 5:
						{
							char del;
							cout << " sei sicuro di voler eliminare tutto ? s/n" << endl ;
							cin >>del;
							if(del=='s' || del=='S')
							{
								int res=bancarotta();
                                if(res==-1)
                                {
                                    cout << " Non riesco ad accedere al file " << endl ;
                                }else if(res==-2)
                                {
                                    cout << " Hai inserito una password sbagliata " << endl ;
                                    break;
                                }else if(res==0)
                                {
                                    cout << " Mi dispiace che la tua azienda sia fallita " << endl ; 
                                }
							}							
						}break;

						default:
						    cout << " Numero non corrispondente " << endl ;
			} // Fine switch scegli operazione 
            }else
            {
                goto retype;
            }    
        }//! leggi password
        }break; // direttore 
        
        case 2: //dipendente
        {
            string id,password,tocheck;
			ifstream leggiPassword("password.txt");
			if(!leggiPassword)
			{
				cout << " Errore non posso verificare le password " << endl ;
				return -1;
			}else
			{
				while(!leggiPassword.eof())
				{
					leggiPassword>>id;
					if(id=="dipendente")
					{
						leggiPassword >> password;
					}
				}
				leggiPassword.close();	
				rewrite:
				cout << " Inserire password  accesso dipendente " << endl ;	
				cin >> tocheck;
				if(password==tocheck)
				{
					int scegli;
					string op[]={"mostra prodotti","modifica prodotto","elimina prodotto","aggiungi prodotto","vendi","guadagno totale"};
					do
					{
						cout << " scegliere l' operazione da effettuare " << endl ;
						for ( int i=0; i< 6; i++)
						{
							cout << i+1 << "\t" << op[i] << endl ;
						}
						cin >> scegli;
					}while(scegli > 7 || scegli <1 );
					
					switch(scegli)
					{
						case 1:
						{
							int res=stampaProdotti();
                            if(res==-1)
                            {
                                cout << " Errore non riesco ad accedere al file " << endl ; 
                            }
						}break; // Fino a qua va bene 

						case 2:
						{
							string codiceModifica;
							cout << " Modifica di un prodotto " << endl ; 
							cout << " Inserire il codice del prodotto da modificare " << endl ;
							cin>>codiceModifica;
                            int res = modificaProdotto(codiceModifica);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere ad uno  o piu' file  " << endl ;
                            }else if(res==0)
                            {
                                cout << " Modifica Avvenuta " << endl ; 
                            }
							
						}break;

						case 3:
						{		
							string codiceElimina;
							cout << " Eliminazione di un prodotto " << endl ; 
							cout << " Inserire il codice del prodotto da eliminare " << endl ;
							cin>>codiceElimina;
                            int res = eliminaProdotto(codiceElimina);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere ad uno  o piu' file  " << endl ;
                            }else if(res==0)
                            {
                                cout << " Modifica Avvenuta " << endl ; 
                            }
						}break;

						case 4:
						{
							//Aggiungi un prodotto 
							string codice, nomeprodotto, tipoProdotto;
							int numero;	
							double prezzo;
							cout << " Inserire il codice " << endl ;
							cin >> codice ;
							cout << " Inserire il numero " << endl ;
							cin>>numero;
							cout << " Inserire il nome " << endl ;
							cin>>nomeprodotto;
							cout << " Inserire il tipo " << endl ;
							cin >> tipoProdotto;
							cout << " Inserire il prezzo " << endl ;
							cin>>prezzo;
                            int res=aggiungiProdotto( codice,  numero,  nomeprodotto, tipoProdotto,prezzo);
                            if(res==-1)
                            {
                                cout << " Non riesco ad accedere al file " << endl ; 
                            }else if(res==0)
                            {
                                cout << " Ok ho inserito i dati ... " << endl ; 
                            }
							
						}break;

						case 5:
						{
                                string codiceVendita;
                                cout << " Vendita di un prodotto " << endl ;
                                cout << " Inserire il codice dell' oggetto venduto " << endl ;
                                cin >>codiceVendita;
                                int res=vendiProdotto(codiceVendita);
                                if(res==-1)
                                {
                                    cout << " Non riesco ad accedere a uno o piu file " << endl ;
                                }else if(res==0)
                                {
                                    cout << " Vendita effettuata " << endl ; 
                                }
						}break;

                        case 6:
                        {
                            cout << " Resoconto delle vendite totali " << endl  ;
                            double res=vendite();
                            if(res==-1)
                            {
                                cout << " Errore accesso ai file " << endl ; 
                            }else 
                            {
                                cout << " Totale merci vendute euro : " << res << endl ;
                            }
                        }break;
						default:
						    cout << " Numero non corrispondente " << endl ;
                    } // Fine switch scegli operazione 
                }else
                {
                    goto rewrite;
                }    
            }//! leggi password
        }break; // dipendente
        
        case 3:
        {
            int daEseguire;
            string opcliente[]={"visualizza prodotto","acquista"};
            for ( int i=0 ; i< 2; i++)
            {
                cout << i+1 << "\t" << opclient[i] << endl ; 
            }
            cout << " scelga l' operazione da effettuare " << endl 
            cin>>daEseguire;
            switch(daEseguire)
            {
                case 1:
                {
                    int res=stampaProdotti();
                    if(res==-1)
                    {
                        cout << " Errore non riesco ad accedere al file " << endl ; 
                    }
                }break;
                
                case 2:
                {
                    string codiceVendita;
                    cout << " Acquista un prodotto " << endl ;
                    int res=stampaProdotti();
                    if(res==-1)
                    {
                        cout << " Errore non riesco ad accedere al file " << endl ; 
                    }
                    cout << " Inserire il codice dell' oggetto da comprare" << endl ;
                    cin >>codiceVendita;
                    res=vendiProdotto(codiceVendita);
                    if(res==-1)
                    {
                        cout << " Non riesco ad accedere a uno o piu file " << endl ;
                    }else if(res==0)
                    {
                        cout << " Acquisto effettuato " << endl ; 
                    }
                }break;
                
                default:
                    cout << " Numero non corrispondente " << endl ; 
            }
        }break; //cliente
        
        default:
        {
            cout << " Numero errato " << endl ; 
        }
    }//Fine di int main (diventa fine switch ) 
}
