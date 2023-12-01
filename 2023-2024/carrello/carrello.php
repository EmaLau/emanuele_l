<?php

class Carrello
{
    var $articoli = array();
    var $quantita = array();

    function aggiungi_carrello($a, $q)
    {
        $position = count($this->articoli);
        $trovato = 0;
        for ($i = 0; $i < count($this->articoli); $i++) {
            if ($this->articoli[$i] == $a)
                $trovato = 1;
        }
        if ($trovato == 1) {
            $this->aggiorna($a, $q);
        } else {
            $this->articoli[$position] = $a;
            $this->quantita[$position] = $q;
        }
    }


    function aggiorna($n, $q)
    {
        $posizione = -1;
        for ($i = 0; $i < count($this->articoli); $i++) {
            if ($this->articoli[$i] == $n)
                $posizione = $i;
        }
        if ($posizione == -1) {
            echo "Prodotto non trovato <br>";
        } else {
            $this->quantita[$posizione] = $q;
        }
    }

    function togli_carrello($a)
    {
        $posizione = -1;
        for ($i = 0; $i < count($this->articoli); $i++) {
            if ($this->articoli[$i] == $a)
                $posizione = $i;
        }
        if ($posizione != -1) {
            $count = 0;

            for ($i = 0; $i < count($this->articoli); $i++) {
                if ($this->articoli[$i] != $a) {
                    $app_ar[$count] = $this->articoli[$i];
                    $app_qr[$count] = $this->quantita[$i];
                    $count++;
                }
            }
            unset($this->articoli);
            unset($this->quantita);

            for ($i = 0; $i < count($app_ar); $i++) {
                $this->articoli[$i] = $app_ar[$i];
                $this->quantita[$i] = $app_qr[$i];
            }
        } else {
            echo "prodotto non trovato! <br>";
        }
    }

    function stampa()
    {
        for ($i = 0; $i < count($this->articoli); $i++) {
            echo "<b>Articoli:</b>" . $this->articoli[$i] . "<br>";
            echo "<b>Quantità:</b>" . $this->quantita[$i] . "<br>";
        }
    }
}