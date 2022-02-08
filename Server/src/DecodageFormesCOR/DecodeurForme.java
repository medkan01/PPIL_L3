package DecodageFormesCOR;

import Forme.Forme;

public class DecodeurForme {
    public static Forme decode(String s) {
        DecodeCOR d;

        d = new DecodeSegment(null);
        d = new DecodeCercle(d);
        d = new DecodeTriangle(d);

        return d.decodeForme(s);
    }
}
