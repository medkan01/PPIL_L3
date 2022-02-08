package DecodageFormesCOR;

import java.util.Arrays;

import Forme.Forme;

public class DecodeSegment extends DecodeCOR {
    public DecodeSegment(DecodeCOR suivant) {
        super(suivant);
    }

    public Forme decodeForme1(String str) {
        String[] newStr = str.split("/");
        String type = newStr[0];
        String couleur = newStr[newStr.length - 1];
        String[] points = Arrays.copyOfRange(newStr, 1, newStr.length - 1);

        if (type.equals("segment"))
            return new Forme(type, points, couleur);
        return null;
    }
}
