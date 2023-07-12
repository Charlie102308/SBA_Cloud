from flask import Flask, request 
    # Initialize our Flask Application  
app = Flask(__name__)  
    
@app.route('/', methods=['GET'])  
def index():  
    return '<h1>Hello World!</h1>'

if __name__ == '__main__':
    app.run(debug=True)