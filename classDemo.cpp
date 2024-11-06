    #include <iostream>
    using namespace std;
     
    // Class declaration
    class Rectangle
    {

    // Public access modifiers
    public:
      // Constructor
      Rectangle(int width, int height);

      // Destructor
      ~Rectangle() {}
      
      // Overloading
      void drawShape() const;
      void drawShape(int width, int height) const;
    
    // Private access modifiers
    private:
      int width;
      int height;
    };
    
    Rectangle::Rectangle(int newWidth, int newHeight)
    {
      width = newWidth;
      height = newHeight;
    }

    // Member function for drawing 
    void Rectangle::drawShape() const
    {
      drawShape(width, height);
    }
 
    void Rectangle::drawShape(int width, int height) const
    {
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++) { cout << "*"; }
        cout << endl;
      }
    }
     
    // Main loop
    int main()
    {

      // Variables
      int userWidth, userHeight;

      // User input
      cout << "\nEnter Rectangle width: ";
      cin >> userWidth;

      cout << "Enter Rectangle length: ";
      cin >> userHeight;

      // Instancing the class
      Rectangle userRec(userWidth, userHeight);
      
      // Output
      cout << "<| Result |>\n\n";
      userRec.drawShape();

    }
