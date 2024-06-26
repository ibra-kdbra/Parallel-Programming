package org.mazurov.robusta;

import java.io.*;

public class RLE {
    private int w;
    private int h;
    private int[] state;

    public int getW() {
        return w;
    }

    public int getH() {
        return h;
    }

    public int[] getState() {
        return state;
    }

    public int getState(int x, int y) {
        return state[y * w + x];
    }

    /* Acorn pattern:
     *
     *     X
     *       X
     *    XX  XXX
     */
    public static RLE getAcorn() {
        int w = 200;
        int h = 200;
        int[] state = new int[w * h];
        int start = h/2*w + w/2;
        state[start] = 1;
        state[start+1] = 1;
        state[start+4] = 1;
        state[start+5] = 1;
        state[start+6] = 1;
        state[start+w+3]   = 1;
        state[start+2*w+1] = 1;

        RLE rle = new RLE();
        rle.w = w;
        rle.h = h;
        rle.state = state;
        return rle;
    }

    public static RLE fromFile(String fname)
    {
        try {
            if (fname == null || fname.length() == 0) {
                System.err.println("ERROR: empty file name");
            }
            char ch = fname.charAt(0);
            String resourceName = ch == '/' ? fname : "/" + fname;

            InputStream is = RLE.class.getResourceAsStream(resourceName);
            BufferedReader in = is != null ? new BufferedReader(new InputStreamReader(is)) :
                    new BufferedReader(new FileReader(fname));

            // Skip comments
            String line;
            for (;;) {
                line = in.readLine();
                if (line.charAt(0) != '#') {
                    break;
                }
            }

            // Parse parameters
            int w = 0;
            int h = 0;
            String[] tokens = line.split("[ ,]+");
            for (int i=0; i<tokens.length; ++i) {
                if (tokens[i].equals("x")) {
                    w = Integer.parseInt(tokens[i+2]);
                    i += 2;
                }
                else if (tokens[i].equals("y")) {
                    h = Integer.parseInt(tokens[i+2]);
                    i += 2;
                }
                else {
                    break;
                }
            }

            // Read the state
            int[] state = new int[w * h];
            int idx = 0;
            int rcnt = 0;
            loop:       for (;;) {
                line = in.readLine();
                if (line == null) {
                    break;
                }
                for (int i=0; i<line.length(); ++i) {
                    char c = line.charAt(i);
                    switch (c) {
                        case ' ': case '\t': case '\n': case '\r':
                            break;
                        case '0': case '1': case '2': case '3': case '4':
                        case '5': case '6': case '7': case '8': case '9':
                            rcnt = rcnt*10 + (c-'0');
                            break;
                        case 'o':
                            if (rcnt == 0) rcnt = 1;
                            for (int j=0; j<rcnt; ++j) {
                                state[idx++] = 1;
                            }
                            rcnt = 0;
                            break;
                        case 'b':
                            if (rcnt == 0) rcnt = 1;
                            for (int j=0; j<rcnt; ++j) {
                                state[idx++] = 0;
                            }
                            rcnt = 0;
                            break;
                        case '$':
                            if (rcnt == 0) rcnt = 1;
                            int nidx = ((idx - 1)/w + rcnt) * w;
                            while (idx < nidx) {
                                state[idx++] = 0;
                            }
                            rcnt = 0;
                            break;
                        case '!':
                            while (idx < state.length) {
                                state[idx++] = 0;
                            }
                            break loop;
                    }
                }
            }

            RLE rle = new RLE();
            rle.w = w;
            rle.h = h;
            rle.state = state;
            return rle;
        }
        catch(IOException e) {
            System.err.println("ERROR: bad file: " + fname);
            return null;
        }
    }

}
