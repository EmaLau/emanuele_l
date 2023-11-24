<?php
/*
class convertitore {
    private $tassocambio;

    public function __construct($tassocambio){
        $this->tassocambio = $tassocambio;
    }

    public function convertiDollaroEuro($importoindollari){
        $importoineuro = $importoindollari * $this->tassocambio;
        return $importoineuro;
    }

    public function stamparisultato($importoindollari, $importoineuro){
        echo "Importo in Dollari: $importoindollari USD\n";
        echo "Importo in Euro: $importoineuro EUR\n";
    }
}


*/
/*
class Libro
{
    private $nomelibro;
    private $prezzo;
    private $numeroscaffale;
    private $numeropagine;
    private $casaeditrice;


    public function inizializza($nomelibro, $prezzo, $numeroscaffale, $numerpagine, $casaeditrice)
    {
        $this->nomelibro = $nomelibro;
        $this->prezzo = $prezzo;
        $this->numeroscaffale = $numeroscaffale;
        $this->numeropagine = $numerpagine;
        $this->casaeditrice = $casaeditrice;
    }

    public function mostra()
    {
        echo "Nome del libro" . implode(" ", $this->nomelibro) . "\n";
        echo "Prezzo: $" . $this->prezzo . "\n";
        echo "Numero di scaffale: " . $this->numeroscaffale . "\n";
        echo "Numero di pagine: " . $this->numeropagine . "\n";
        echo "Casa editrice: " . $this->casaeditrice . "\n";
    }


    public function applicasconto()
    {
        $sconto = $this->prezzo * 0.10;
        $this->prezzo -= $sconto;

    }
}

*/

/*
class Massimi {
    plublic static function max($num1, $num2){
        return ($num1>$num2) ? $num1 : $num2;
}

public static function min($num1, $num2){
        return ($num1 < $num2) ? $num1 : $num2;
}

}
*/

/*
class Negozio{
    private $proprietario;
    private $nomenegozio;

    public function __construct($nomenegozio)
    {
        $this->proprietario = "Nessun proprietario specificato";
        $this->nomenegozio = $nomenegozio;
    }

    public function mostrastato(){
        echo "Proprietario:  " . $this->proprietario . "\n";
        echo "Nome del Negozio: " . $this->nomenegozio "\n"
    }
}


*/

/*
class ContoCorrente{
    private $nome;
    private $codiceconto;
    private $saldo;

    public function __construct($nome){
        $this->$nome;
        $this->codiceconto=uniqid();
        $this->saldo = 0;
    }

    public function __construct($nome, $codiceconto){
        $this->nome = $nome;
        $this->codiceconto = $codiceconto;
        $this->saldo = 0;
    }

    public function __construct($nome, $codiceconto, $saldo){
        $this->nome = $nome;
        $this->saldo = $saldo;
        $this->codiceconto = $codiceconto;
    }

    public function mostrastato(){
        echo "Nome: " . $this->nome . "\n";
        echo "Codice Conto: " . $this->codiceconto . "\n";
        echo "Saldo: $" . $this->saldo . "\n";
    }
}
*/


/*
class Prodotto {
    public $codice;
    public $descrizione;

    public function __construct($codice, $descrizione) {
        $this->codice = $codice;
        $this->descrizione = $descrizione;
    }

    public static function withCodice($codice) {
        return new self($codice, null);
    }

    public static function withDescrizione($descrizione) {
        return new self(null, $descrizione);
    }
}

*/
/*
class Fattura {
    public $cliente;
    public $numeroProdotti;

    public function __construct($cliente, $numeroProdotti) {
        $this->cliente = $cliente;
        $this->numeroProdotti = $numeroProdotti;
    }

    public static function withCliente($cliente) {
        return new self($cliente, null);
    }

    public static function withNumeroProdotti($numeroProdotti) {
        return new self(null, $numeroProdotti);
    }
}

class LineaBus {
    public $numeroIdentificativo;
    public $capolineaPartenza;
    public $capolineaArrivo;

    public function __construct($numeroIdentificativo, $capolineaPartenza, $capolineaArrivo) {
        $this->numeroIdentificativo = $numeroIdentificativo;
        $this->capolineaPartenza = $capolineaPartenza;
        $this->capolineaArrivo = $capolineaArrivo;
    }

}
*/

/*
class Auto {
    public $marca;
    public $modello;
    public $targa;
    public $annoImmatricolazione;

    public function __construct($marca, $modello, $targa, $annoImmatricolazione) {
        $this->marca = $marca;
        $this->modello = $modello;
        $this->targa = $targa;
        $this->annoImmatricolazione = $annoImmatricolazione;
    }

}
*/
/*
class Studente {
    public $cognome;
    public $nome;
    public $codiceFiscale;
    public $numeroMatricola;

    public function __construct($cognome, $nome, $codiceFiscale, $numeroMatricola) {
        $this->cognome = $cognome;
        $this->nome = $nome;
        $this->codiceFiscale = $codiceFiscale;
        $this->numeroMatricola = $numeroMatricola;
    }

}
*/
/*
class AggiornaData {
    public $timestamp;

    public function __construct() {
        $args = func_get_args();
        $numArgs = func_num_args();

        if ($numArgs == 0) {
            $this->timestamp = time()
        } elseif ($numArgs == 1) {
            $arg = $args[0];
            if (is_numeric($arg)) {
                $this->timestamp = $arg;
            } elseif (is_string($arg)) {
                $this->timestamp = strtotime($arg);
            }
        } elseif ($numArgs == 3) {
            $day = $args[0];
            $month = $args[1];
            $year = $args[2];
            $this->timestamp = strtotime("$day-$month-$year");
        }
    }
}

*/