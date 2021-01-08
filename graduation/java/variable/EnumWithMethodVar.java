//for set value to enums
public class EnumWithMethodVar {
    public static void main(String[] args) {
        System.out.println("Get enum value for Comapny 'eBay': " + EnumCompany.EBAY.getCompanyLetter());
    }
}

enum EnumCompany {
    GOOGLE("G"), YAHOO("Y"), EBAY("E"), PAYPAL("P");
    private String companyLetter;
    //this constructor is automatially called for each enums, AKA GOOGLE("G")
    private EnumCompany(String s) {
        companyLetter = s;
    }
    public String getCompanyLetter() {
        return companyLetter;
    }
}

