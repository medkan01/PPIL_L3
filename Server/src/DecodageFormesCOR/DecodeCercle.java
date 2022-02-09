package DecodageFormesCOR;

import java.util.Arrays;

import Forme.Forme;

public class DecodeCercle extends DecodeCOR {
    public DecodeCercle(DecodeCOR suivant) {
        super(suivant);
    }

    protected Forme decodeForme1(String str) {
        String[] newStr = str.split("/");

        if (newStr.length <= 1)
            return null;

        String type = newStr[0];
        String couleur = newStr[newStr.length - 1];
        String[] points = Arrays.copyOfRange(newStr, 1, newStr.length - 1);

        if (type.equals("cercle"))
            return new Forme(type, points, couleur);
        return null;
    }

}
