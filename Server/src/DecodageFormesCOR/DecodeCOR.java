package DecodageFormesCOR;

import Forme.Forme;

public abstract class DecodeCOR extends Decode {
    DecodeCOR suivant;

    public DecodeCOR(DecodeCOR suivant) {
        this.suivant = suivant;
    }

    abstract protected Forme decodeForme1(String str);

    public Forme decodeForme(String str) {
        Forme f = this.decodeForme1(str);

        if (f != null)
            return f;

        if (this.suivant != null)
            return this.suivant.decodeForme(str);

        return null;
    }
}
