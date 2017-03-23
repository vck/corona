from flask import (
    render_template,
    request,
    Flask
)

server = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/blink/<int:times>')
def blink(times):
    times = int(times)
    blink(times)
