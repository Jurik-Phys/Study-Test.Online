import style from './UserResultTest.module.css'
import { useNavigate, useParams } from 'react-router-dom'
import { useState, useEffect } from 'react'
import axios from 'axios';

const UserResultTest = () => {
  const [loading, setLoading] = useState(true);
  const { sessionId } = useParams();
  const navigate = useNavigate();
  const [result, setResult] = useState();

  useEffect( () => {
    const getResultData = async () => {
      try {
        const response = await axios.get(`http://localhost:7500/session/${sessionId}`);
        const getResult = response.data
        setLoading(false)
        if (getResult !== null && getResult !== undefined){
          const oldObj = JSON.stringify(result)
          const newObj = JSON.stringify(getResult)
          if ( oldObj !== newObj){
            setResult(getResult)
          }
        }
      }
      catch (error) {
        console.error('Error fetching data:', error);
      }
    }

    getResultData();
    }, [sessionId, result])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }
  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>Результаты</div>
        <div className={style.text}>
          <div>
            <label className={style.sText}>
              {result["testInfo"]["section"]}
            </label>
            <ul>
              <li>
                {/*
                <label className={style.sText}>
                  Annotation.
                </label> It is the activity of annotating something. She retained a number of copies for further annotation
                */}
              </li>
              <li>
                <label className={style.sText}>
                  Начало:
                </label> {result["beginAt"]}
              </li>
              <li>
                <label className={style.sText}>
                  Завершение:
                </label> {result["endAt"]}
              </li>
              <li>
                <label className={style.sText}>
                  Bопросов всего:
                </label> {result["testInfo"]["totalQuestions"]}
              </li>
              <li>
                <label className={style.sText}>
                  Отвечено вопросов:
                </label> {result["testInfo"]["doneQuestions"]}
              </li>
              <li>
                <label className={style.sText}>
                  Итоговая оценка:
                </label> {result["result"]}
              </li>
            </ul>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate("/")} >Close</button>
        </div>
      </div>
  );
}

export default UserResultTest;
