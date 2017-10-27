from flask import Flask, render_template, send_file

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('home.html')

@app.route('/img')
def getImg():
    return send_file("../img/capture1.png", mimetype="image/png")

if __name__ == "__main__":
    app.run(debug=True)
