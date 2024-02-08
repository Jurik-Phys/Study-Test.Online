import style from './UserPassingTest.module.css'
import { useNavigate, useParams } from 'react-router-dom'
import { useState, useEffect } from 'react'
import axios from 'axios';

const printQuestionData = (question, questionNumber, questionsTotal, inputClick) => {
  const getInputType = (question) => {

    switch (question["type"]){
      case 'multiple-choice':
        return "checkbox"
      case 'single-choice':
        return "radio"
      default:
        return "single-choice"
    }
  }

  return (
    <div>
      <div className={style.hText}>Вопрос {questionNumber}/{questionsTotal}</div>
      <div className={style.text}>
          <label className={style.qText}>
            {question["body"]}
          </label>
          <div style={{ width: '40vw', height: '48vh', overflow: 'auto', border: '0px solid gray' }} >
          <ul>
            {
            question["answers"].map( (answer, index) => {
            return (
            <li>
              <input type={getInputType(question)} name="name" id={index} value={answer["id"]} onChange={inputClick} /> {answer["body"]}
            </li>
            )
            })
            }
          </ul>
        </div>
      </div>
    </div>
  );
}

const UserPassingTest = () => {
  const { sessionId } = useParams();
  const navigate = useNavigate();
  const [loading, setLoading] = useState(true);
  const [sLoading, setSLoading] = useState(true);
  const [question, setQuestion] = useState(null)
  const [questionNumber, setQuestionNumber] = useState(null)
  const [questionsTotal, setTotalQuestions] = useState(null)
  const [answers, setAnswers] = useState([])


  useEffect( () => {
    const getSessionData = async () => {
      try {
        const response = await axios.get(`http://localhost:7500/session/${sessionId}`);
        const sessionResponse = response.data
         const questionNumberLocal = sessionResponse["testInfo"]["doneQuestions"] + 1 ;
        if (questionNumberLocal !== null && questionNumberLocal !== undefined){
          const oldObj = JSON.stringify(questionNumber)
          const newObj = JSON.stringify(questionNumberLocal)
          if ( oldObj !== newObj){
            console.log("[II] =>> 01 =>>")
            setQuestionNumber(questionNumberLocal)
            setTotalQuestions(sessionResponse["testInfo"]["totalQuestions"])
          }
          setSLoading(false)
        }
      }
      catch (error) {
        console.error('Error fetching data:', error);
      }
    }
    getSessionData();

  }, [questionNumber, sessionId])

  useEffect( () => {
    const getQuestionData = async () => {
      try {
        const response = await axios.get(`http://localhost:7500/question/${sessionId}`);
        const questResponse = response.data
        if (questResponse !== null && questResponse !== undefined){
          const oldObj = JSON.stringify(question)
          const newObj = JSON.stringify(questResponse)
          if ( oldObj !== newObj){
            console.log("[II] =>> 02 =>>")
            setQuestion(questResponse)
          }
        }
      }
      catch (error) {
        console.error('Error fetching data:', error);
      }
    }

    getQuestionData();
    }, [question, sessionId])

  if (loading && sLoading){
    return (
      <div className={style.bodyStyle}>LOADING!!!</div>
    )
  }

  const clickButton = () => {

    if ( answers.length > 0){
      let answersObj = [];
      answers.map( (answer,index) => {
        answersObj.push({id: answer, body: "-"} )
        return null
      })

      const postObj = {
        session_id: sessionId,
        question_id: question["id"],
        answers: answersObj
      }
      const postAnswer = async () => {
        try {
          const response = await axios.post('http://localhost:7500/answers', postObj);
          console.log('Response:', response.data);
          const lastQuestion = questionsTotal - questionNumber === 0 ? true : false

          if (!lastQuestion){
            window.location.reload();
          }
          else {
            console.log("Запрос результата")
            navigate(`/user-result-test/${sessionId}`)

          }

        } catch (error) {
          console.error('Error:', error);
        }
      }
      postAnswer();

    }
    else {
      alert("Сначала необходимо сделать выбор!")
    }
  }

  const inputClick = (event)  =>{
    switch (event.target.type){
      case 'checkbox':
        if (event.target.checked){
          // "ADD Answer ID
          if ( answers.length > 0){
            const newAnswersArray = [...answers, event.target.value ]
            setAnswers(newAnswersArray)
          }
          else {
            setAnswers([event.target.value])
          }
        }
        else {
          // "DEL Answer ID
          const newAnswersArray = answers.filter(item => item !== event.target.value );
          setAnswers(newAnswersArray)
        }
        break
      default:
        // SET Answer ID
        if (event.target.checked){
          setAnswers([event.target.value])
        }
    }
  }

  return (
      <div className={style.bodyStyle}>
          {printQuestionData(question, questionNumber, questionsTotal, inputClick)}
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ clickButton } >Next</button>
        </div>
      </div>
  );
}

export default UserPassingTest;
