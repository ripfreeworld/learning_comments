
/**

Exception Handling:
					-Früher gab es "traditional Error Handling"
							
							->Einen sonderwert zurück geben beim Fehlerfall ->Library
							->Cleint muss immer den zurückgegebenen Wert überprüfen
							int x;
							cin>>x; //user hat -5 eingegeben
							int result = fakul(x);
							if(result > 0){
										mit Result weiterarbeiten
										}
						-Dieser Ansatz hat Nachteile:
										-Es ist nicht immer einfach einen Sonderwert zu finden
										-Der Cleint kann vergessen zu überprüfen
										-Aus einer Funktion kommt nur einen Wert zurück mit retrun
										-Konstrukturen geben keinen Wert zurück
						Ausweg:
									void fakul(int n, int& result, bool& err)
									{
										if(n < 0)
												err = true;
										else{
											result = normale Berechnung
											err = false;
										}
									}
							->Dies geht leider bei Operator overloading nicht
							 da Anzahl der Argumente bei Operatoren darf nicht geändert werden!
							 
Exception Mechanismus:
						Lib Code:
									-error detection and raise signal
									->throw Statement
						Cleint Code:
									try{
										call Lib code, which may be a danger 
										}
										catch(Exceptiontype ex){
											Handling
										}
										
					
			
*/