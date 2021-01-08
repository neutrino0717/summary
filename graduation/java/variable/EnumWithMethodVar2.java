public class EnumWithMethodVar2 {
    //enum Power{ STRONG, MODERATE, WEAK; }
    enum Power{ 
        STRONG(3), MODERATE(2), WEAK(1); 
        //the var and constructor are for each enums
        int strength;
        private Power(int i){
            strength = i;
        }
        public int getPower(){
            return strength;
        }
    }
    public static void main(String[] args){
        Power player1 = Power.WEAK;
        Power player2 = Power.MODERATE;
        Power player3 = Power.STRONG;
        System.out.println("The strength of the Strong player is: " + player3.getPower());
        System.out.println("The strength of the Strong player is: " + Power.STRONG.getPower());
    }

}
